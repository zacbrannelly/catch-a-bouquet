#include "katho.h"

#include <gba_sprites.h>
#include "obj_utils.h"
#include "game_state.h"
#include "constants.h"

int const KATHO_FLOOR_POS = FRAME_HEIGHT - KATHO_HEIGHT;

void init_katho(GameState* game_state) {
  // Katho NPC sprite (16x32@8bpp)
  game_state->katho_buffer.attr0 = OBJ_256_COLOR | OBJ_SHAPE(2);
  game_state->katho_buffer.attr1 = OBJ_SIZE(2) | ATTR1_FLIP_X;
  game_state->katho_buffer.attr2 = KATHO_BASE_TILE_IDX * 2;

  obj_set_pos(&game_state->katho_buffer, 30, KATHO_FLOOR_POS);
  obj_update(&game_state->katho_buffer, KATHO_SPRITE_ID);
}
