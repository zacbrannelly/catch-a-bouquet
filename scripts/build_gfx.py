import os
import json
import fire
from PIL import Image

from common.templates import (
  ASM_FILE_TEMPLATE,
  HALF_WORD_DATA_ROW_TEMPLATE,
  WORD_DATA_ROW_TEMPLATE,
  INCLUDE_FILE_TEMPLATE,
  TILES_DECLARATION_TEMPLATE,
  PALETTE_DECLARATION_TEMPLATE,
)
from common.conversion import (
  rgba32_tuple_to_bgr15,
  rgba32_to_bgr15,
)


def build_shared_palette(images, output_base_name, output_dir, transparent_color_bgr15):
  # Read palette from each image and merge them into a single pallete.
  palette = set()
  for image in images:
    if image.mode != "RGBA":
      image = image.convert("RGBA")

    colors = [rgba32_tuple_to_bgr15(p) for p in list(image.getdata())]
    palette.update(colors)

  palette = list(palette)
 
  # Put the transparent color at the start of the palette.
  if transparent_color_bgr15 in palette:
    palette.remove(transparent_color_bgr15)
    palette.insert(0, transparent_color_bgr15)

  return palette


def get_output_palette_path(output_base_name, output_dir):
  return os.path.join(output_dir, f"{output_base_name}_palette.s")


def write_palette_data(palette, output_base_name, output_dir):
  # Render the data as .hword rows.
  data_rows = []
  for eight_byte_row in range(0, len(palette), 8):
    row = palette[eight_byte_row:eight_byte_row + 8]
    row = HALF_WORD_DATA_ROW_TEMPLATE.format(
      data=", ".join([f"0x{p:04X}" for p in row])
    )
    data_rows.append(row)
  data_rows = "\n".join(data_rows)

  # Render the palette data to an assembly file.
  assembly_output = ASM_FILE_TEMPLATE.format(
    variable_name=f"{output_base_name}_palette",
    data_rows=data_rows,
  )

  # Write the assembly output to a file.
  output_path = get_output_palette_path(output_base_name, output_dir)
  with open(output_path, "w") as f:
    f.write(assembly_output)

  return palette


def main(
  image_paths: str = "../gfx/spritesheet.png, ../gfx/puppy.png",
  output_base_name: str = "test",
  output_dir: str = "./",
  transparent_color: int = 0xFF00FF00,
  default_width_in_tiles: int = 2,
  default_height_in_tiles: int = 4,
  two_dimensional: bool = False,
):
  """
  Convert images to assembly data with a shared palette.
  """

  # Convert the transparent color to bgr15.
  transparent_color_bgr15 = rgba32_to_bgr15(transparent_color)

  # Load the images.
  print(f"Loading images from {image_paths}")
  image_paths = [p.strip() for p in image_paths.split(",")]
  images = [Image.open(p) for p in image_paths]

  # Build a shared palette from the images.
  palette = build_shared_palette(
    images,
    output_base_name,
    output_dir,
    transparent_color_bgr15
  )
  print(f"Built palette with {len(palette)} colors.")

  # Write the palette data to an assembly file.
  write_palette_data(palette, output_base_name, output_dir)
  print(f"Output palette data to {get_output_palette_path(output_base_name, output_dir)}")

  # Load the metadata JSON for each image.
  metadata = {
    p: json.load(open(p.replace(os.path.splitext(p)[1], ".json")))
    for p in image_paths
  }

  # Build tiles from images using shared palette.
  tileset_by_image = {}
  assembly_outputs = []
  for path, image in zip(image_paths, images):
    print(f"Processing {path}")
    print(f"  Metadata: {metadata[path]}")

    width_in_tiles = metadata[path]["width_in_tiles"]
    height_in_tiles = metadata[path]["height_in_tiles"]

    if image.mode != "RGBA":
      image = image.convert("RGBA")

    num_sprites = image.width * image.height // (width_in_tiles * 8 * height_in_tiles * 8)

    tile_data = []
    accum_x = 0
    accum_y = 0
    for sprite_idx in range(num_sprites):
      if not two_dimensional:
        # 1D Mapping
        for y in range(height_in_tiles):
          for x in range(width_in_tiles):
            for i in range(8 * 8):
              pixel_x = accum_x + x * 8 + i % 8
              pixel_y = accum_y + y * 8 + i // 8

              color = image.getpixel((pixel_x, pixel_y))
              color = rgba32_tuple_to_bgr15(color)
              index = palette.index(color)
              tile_data.append(index)

        accum_x += width_in_tiles * 8
        if accum_x >= image.width:
          accum_x = 0
          accum_y += height_in_tiles * 8
      else:
        # TODO: 2D Mapping
        pass
    
    tileset_by_image[path] = tile_data

    # 1 byte per pixel (256 color mode).
    # Export as 8 words per row in assembly.
    num_words = len(tile_data) // 4
    data_rows = []

    for four_word_row in range(0, num_words, 8):
      row = tile_data[four_word_row * 4:four_word_row * 4 + 32]

      # Pack the 4 pixels/bytes into a single word.
      row = [
        (row[i + 3] << 24) | (row[i + 2] << 16) | (row[i + 1] << 8) | row[i]
        for i in range(0, len(row), 4)
      ]

      row = WORD_DATA_ROW_TEMPLATE.format(
        data=", ".join([f"0x{p:08X}" for p in row])
      )
      data_rows.append(row)
    data_rows = "\n".join(data_rows)

    variable_name = os.path.splitext(os.path.basename(path))[0]
    variable_name = f"{output_base_name}_{variable_name}_tiles"
    assembly_output = ASM_FILE_TEMPLATE.format(
      variable_name=variable_name,
      data_rows=data_rows,
    )
    assembly_outputs.append(assembly_output)

  # Write the assembly output to a file.
  output_path = os.path.join(output_dir, f"{output_base_name}.s")
  with open(output_path, "w") as f:
    f.write("\n\n".join(assembly_outputs))

  include_output = INCLUDE_FILE_TEMPLATE.format(
    upper_case_header_name=output_base_name.upper(),
    declarations="".join([
      TILES_DECLARATION_TEMPLATE.format(
        variable_name=f"{output_base_name}_{os.path.splitext(os.path.basename(path))[0]}",
        tiles_length_bytes=len(tileset_by_image[path]),
        tiles_length_words=len(tileset_by_image[path]) // 4,
      )
      for path in image_paths
    ])
  )

  include_output_path = os.path.join(output_dir, f"{output_base_name}.h")
  with open(include_output_path, "w") as f:
    f.write(include_output)

  include_output = INCLUDE_FILE_TEMPLATE.format(
    upper_case_header_name=f"{output_base_name.upper()}_PALETTE",
    declarations=PALETTE_DECLARATION_TEMPLATE.format(
      output_name=output_base_name,
      palette_length_bytes=len(palette) * 2,
      palette_length_half_words=len(palette),
    )
  )

  include_output_path = os.path.join(output_dir, f"{output_base_name}_palette.h")
  with open(include_output_path, "w") as f:
    f.write(include_output)


if __name__ == "__main__":
  fire.Fire(main)
