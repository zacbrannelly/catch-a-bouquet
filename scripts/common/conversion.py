from typing import Tuple


def rgba32_tuple_to_bgr15(rgba32_tuple: Tuple[int, int, int]) -> int:
  r5 = (rgba32_tuple[0] >> 3) & 0x1F
  g5 = (rgba32_tuple[1] >> 3) & 0x1F
  b5 = (rgba32_tuple[2] >> 3) & 0x1F
  return (
    (b5 << 10) |
    (g5 << 5) |
    r5
  )


def rgba32_to_bgr15(rgba32: int):
  r = (rgba32 >> 24) & 0xFF
  g = (rgba32 >> 16) & 0xFF
  b = (rgba32 >> 8) & 0xFF
  
  r5 = (r >> 3) & 0x1F
  g5 = (g >> 3) & 0x1F
  b5 = (b >> 3) & 0x1F

  return (
    (b5 << 10) |
    (g5 << 5) |
    r5
  )
