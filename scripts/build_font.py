import fire
from typing import List
from PIL import Image
from common.conversion import (
  rgba32_tuple_to_bgr15,
  rgba32_to_bgr15,
)
from common.templates import (
  pack_bytes_into_word_data_rows,
  build_asm_data_file,
  build_tiles_declaration,
  build_include_file,
)

TILE_SIZE = 8

def build_tile_data(image, x_in_pixels, y_in_pixels, width, height) -> List[int]:
  tile_data = []
  for y in range(0, height, TILE_SIZE):
    for x in range(0, width, TILE_SIZE):
      tile = []
      for tile_y in range(TILE_SIZE):
        for tile_x in range(TILE_SIZE):
          pixel_x = x_in_pixels + x + tile_x
          pixel_y = y_in_pixels + y + tile_y
          color = image.getpixel((pixel_x, pixel_y))
          color = rgba32_tuple_to_bgr15(color)
          tile.append(1 if color > 0 else 0)
      tile_data.extend(tile)
  return tile_data


def main(
  font_path: str,
  output_dir: str = ".",
  output_base_name: str = "font",
  character_width: int = 16,
  character_height: int = 16,
  character_spacing: int = 2,
):
  font_image = Image.open(font_path)
  font_image = font_image.convert("RGBA")

  width_in_characters = font_image.width // character_width
  height_in_characters = font_image.height // character_height

  total_tile_data = []
  for y in range(0, font_image.height, character_height + character_spacing):
    for x in range(0, font_image.width, character_width + character_spacing):
      tile_data = build_tile_data(
        font_image,
        x,
        y,
        character_width,
        character_height
      )
      total_tile_data.extend(tile_data)

  # Build assembly data file.
  data_rows = pack_bytes_into_word_data_rows(total_tile_data)
  assembly_output = build_asm_data_file(
    variable_name=f"{output_base_name}_tiles",
    data_rows=data_rows,
  )

  # Build include file.
  declarations = build_tiles_declaration(
    variable_name=output_base_name,
    tiles_length_bytes=len(total_tile_data),
  )
  include_file = build_include_file(
    upper_case_header_name=f"{output_base_name.upper()}_TILES",
    declarations=declarations,
  )

  # Write the assembly output to a file.
  with open(f"{output_dir}/{output_base_name}.s", "w") as f:
    f.write(assembly_output)

  # Write the declaration output to a file.
  with open(f"{output_dir}/{output_base_name}.h", "w") as f:
    f.write(include_file)


if __name__ == '__main__':
  fire.Fire(main)
