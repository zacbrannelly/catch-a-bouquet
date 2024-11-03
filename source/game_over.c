#include "game_over.h"

#include <gba_systemcalls.h>
#include <gba_input.h>
#include <gba_video.h>
#include <fade.h>
#include <stdio.h>
#include <string.h>

#include "game_over_gfx.h"
#include "text.h"
#include "constants.h"

void init_game_over_screen() {
  // Copy the game over screen to memory (tiles)
  CpuSet(game_overTiles, (void*)CHAR_BASE_ADR(3), game_overTilesLen / 2);
  CpuSet(game_overMap, (void*)SCREEN_BASE_BLOCK(10), game_overMapLen / 2);

  REG_BG0CNT = BG_PRIORITY(1) | TEXTBG_SIZE_256x256 | CHAR_BASE(3) | SCREEN_BASE(10);
}

void game_over_screen(int score) {
  // Back up the current palette
  uint16_t palette[256];
  CpuSet((void*)BG_COLORS, palette, 256);

  uint16_t obj_palette[256];
  CpuSet((void*)OBJ_COLORS, obj_palette, 256);

  FadeToBlack(30);

  // Make the font white
  BG_PALETTE[1] = RGB8(255, 255, 255);

  char score_str[50];
  memset(score_str, '\0', 50);
  sprintf(score_str, "%d", score);
  
  int score_str_len = strlen(score_str);
  int text_width = (score_str_len - 1) * 12;
  render_text(0, 0, score_str);

  REG_BG2X = (-(FRAME_WIDTH / 2 + 16 - text_width / 2)) << 8;
  REG_BG2Y = (-100 << 8);

  // Copy the game over palette to palette memory (offset by 2 to allow for the font color).
  CpuSet(game_overPal, (void*)BG_COLORS + 2 * sizeof(uint16_t), game_overPalLen / 2);

  // Disable BG1
  REG_DISPCNT &= ~BG1_ENABLE;

  // Enable BG0
  REG_DISPCNT |= BG0_ENABLE;

  // Disable OBJ
  REG_DISPCNT &= ~OBJ_ENABLE;

  while (true) {
    VBlankIntrWait();
    scanKeys();

    // Any key press will exit the game over screen
    uint16_t keys = keysDown();
    if (keys > 0) {
      break;
    }
  }

  // Restore the original palette
  CpuSet(palette, (void*)BG_COLORS, 256);

  // Restore the original OBJ palette
  CpuSet(obj_palette, (void*)OBJ_COLORS, 256);

  REG_BG2X = -2 << 8;
  REG_BG2Y = -2 << 8;

  // Enable BG1
  REG_DISPCNT |= BG1_ENABLE;

  // Disable BG0
  REG_DISPCNT &= ~BG0_ENABLE;

  // Enable OBJ
  REG_DISPCNT |= OBJ_ENABLE;
}
