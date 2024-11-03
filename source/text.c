#include "text.h"

#include <gba_base.h>
#include <gba_video.h>
#include <string.h>

int const BLANK_TILE = 28 * 4 - 8;
int const SCREEN_BLOCK_SIZE = 32 * 32;

void* TEXT_SCREEN_BASE = (void*)SCREEN_BASE_BLOCK(9);

// Each character is 16x16 pixels, so 2x2 tiles
uint8_t font_indices[] = {
  // A
  0, 1, 2, 3,
  // B
  4, 5, 6, 7,
  // C
  8, 9, 10, 11,
  // D
  12, 13, 14, 15,
  // E
  16, 17, 18, 19,
  // F
  20, 21, 22, 23,
  // G
  24, 25, 26, 27,
  // H
  28, 29, 30, 31,
  // I
  32, 33, 34, 35,
  // J
  36, 37, 38, 39,
  // K
  40, 41, 42, 43,
  // L
  44, 45, 46, 47,
  // M
  48, 49, 50, 51,
  // N
  52, 53, 54, 55,
  // O
  56, 57, 58, 59,
  // P
  60, 61, 62, 63,
  // Q
  64, 65, 66, 67,
  // R
  68, 69, 70, 71,
  // S
  72, 73, 74, 75,
  // T
  76, 77, 78, 79,
  // U
  80, 81, 82, 83,
  // V
  84, 85, 86, 87,
  // W
  88, 89, 90, 91,
  // X
  92, 93, 94, 95,
  // Y
  96, 97, 98, 99,
  // Z
  100, 101, 102, 103,

  // Blank space in the font sprite sheet
  104, 105, 106, 107,
  108, 109, 110, 111,

  // 1
  112, 113, 114, 115,
  // 2
  116, 117, 118, 119,
  // 3
  120, 121, 122, 123,
  // 4
  124, 125, 126, 127,
  // 5
  128, 129, 130, 131,
  // 6
  132, 133, 134, 135,
  // 7
  136, 137, 138, 139,
  // 8
  140, 141, 142, 143,
  // 9
  144, 145, 146, 147,
  // 0
  148, 149, 150, 151,

  // Space
  152, 153, 154, 155
};

void init_text() {
  // Reset the text screen with blank tiles
  memset(TEXT_SCREEN_BASE, BLANK_TILE, SCREEN_BLOCK_SIZE);

  // Set up the text screen (256x256 pixels)
  REG_BG2CNT = BG_PRIORITY(0) | ROTBG_SIZE_256x256 | CHAR_BASE(2) | SCREEN_BASE(9);
  
  // Offset the text screen by 2 from the edge of the screen
  REG_BG2X = (-2 << 8);
  REG_BG2Y = (-2 << 8);

  // Scale the screen to reduce the size of the text
  REG_BG2PA = 315;
  REG_BG2PB = 0;
  REG_BG2PC = 0;
  REG_BG2PD = 315;

  // Enable the text screen
  REG_DISPCNT |= BG2_ENABLE;
}

void render_character(int x, int y, uint8_t character) {
  int offset = 0;
  if (character == ' ') {
    offset = 38;
  } else if (character == '0') {
    // Edge case for '0' character
    offset = 37;
  } else if (character <= '9') {
    // Number characters
    offset = character - '1' + 26 + 2;
  } else {
    // Alphabet characters
    offset = character - 'a';
  }

  // 16x16 screen block (128x128 pixels)
  // Render the character at the specified x, y position
  for (int i = 0; i < 2; i++) {
    uint16_t tile_indices = *((uint16_t*)&font_indices[offset * 4 + i * 2]);
    void* destination = TEXT_SCREEN_BASE + x + y * 32 + i * 32;
    *((uint16_t*)destination) = tile_indices;
  }
}

void render_text(int x, int y, char* string) {
  memset(TEXT_SCREEN_BASE, BLANK_TILE, SCREEN_BLOCK_SIZE);

  int i = 0;
  while (string[i] != '\0') {
    render_character(x + i * 2, y, string[i]);
    i++;
  }
}
