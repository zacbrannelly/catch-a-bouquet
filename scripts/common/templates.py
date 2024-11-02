from typing import List


ASM_FILE_TEMPLATE = """
	.section .rodata
	.align	2
	.global {variable_name}
	.hidden {variable_name}
{variable_name}:
{data_rows}
"""

def build_asm_data_file(variable_name: str, data_rows: str) -> str:
	return ASM_FILE_TEMPLATE.format(
		variable_name=variable_name,
		data_rows=data_rows,
	)


HALF_WORD_DATA_ROW_TEMPLATE = "  .hword {data}"

def build_half_word_data_rows(half_words: List[int]) -> str:
  data_rows = []
  for eight_byte_row in range(0, len(data_bytes), 8):
    row = palette[eight_byte_row:eight_byte_row + 8]
    row = HALF_WORD_DATA_ROW_TEMPLATE.format(
      data=", ".join([f"0x{p:04X}" for p in row])
    )
    data_rows.append(row)
  return "\n".join(data_rows)

WORD_DATA_ROW_TEMPLATE = "  .word {data}"

def pack_bytes_into_word_data_rows(data_bytes: List[int]) -> str:
	# Export as 8 words per row in assembly.
	num_words = len(data_bytes) // 4
	data_rows = []

	for four_word_row in range(0, num_words, 8):
		row = data_bytes[four_word_row * 4:four_word_row * 4 + 32]

		# Pack the 4 bytes into a single word.
		row = [
			(row[i + 3] << 24) | (row[i + 2] << 16) | (row[i + 1] << 8) | row[i]
			for i in range(0, len(row), 4)
		]

		row = WORD_DATA_ROW_TEMPLATE.format(
			data=", ".join([f"0x{p:08X}" for p in row])
		)
		data_rows.append(row)
	return "\n".join(data_rows)


INCLUDE_FILE_TEMPLATE = """
#ifndef {upper_case_header_name}_H
#define {upper_case_header_name}_H
{declarations}
#endif // {upper_case_header_name}_H
"""

def build_include_file(upper_case_header_name: str, declarations: str) -> str:
	return INCLUDE_FILE_TEMPLATE.format(
		upper_case_header_name=upper_case_header_name,
		declarations=declarations,
	)


TILES_DECLARATION_TEMPLATE = """
#define {variable_name}_tiles_len {tiles_length_bytes}
extern const unsigned int {variable_name}_tiles[{tiles_length_words}];
"""

def build_tiles_declaration(variable_name: str, tiles_length_bytes: int) -> str:
	return TILES_DECLARATION_TEMPLATE.format(
		variable_name=variable_name,
		tiles_length_bytes=tiles_length_bytes,
		tiles_length_words=tiles_length_bytes // 4,
	)


PALETTE_DECLARATION_TEMPLATE = """
#define {output_name}_palette_len {palette_length_bytes}
extern const unsigned short {output_name}_palette[{palette_length_half_words}];
"""

def build_palette_declaration(output_name: str, palette_length_bytes: int) -> str:
	return PALETTE_DECLARATION_TEMPLATE.format(
		output_name=output_name,
		palette_length_bytes=palette_length_bytes,
		palette_length_half_words=palette_length_bytes // 2,
	)
