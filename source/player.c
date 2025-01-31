#include "player.h"

#include <gba_sprites.h>
#include <gba_input.h>
#include "obj_utils.h"
#include "game_state.h"
#include "constants.h"

int const ZAC_FLOOR_POS = FRAME_HEIGHT - ZAC_HEIGHT;

void init_player(GameState* game_state) {
  // Zac Player sprite (16x32@8bpp)
  game_state->zac_buffer.attr0 = OBJ_256_COLOR | OBJ_SHAPE(2);
  game_state->zac_buffer.attr1 = OBJ_SIZE(2) | ATTR1_FLIP_X;
  game_state->zac_buffer.attr2 = ZAC_BASE_TILE_IDX * 2;
  game_state->player = (Sprite*)&game_state->zac_buffer;

  game_state->player_collider.min_x = 100;
  game_state->player_collider.max_x = 100 + ZAC_WIDTH;
  game_state->player_collider.min_y = ZAC_FLOOR_POS;
  game_state->player_collider.max_y = ZAC_FLOOR_POS + ZAC_HEIGHT;

  obj_set_pos(&game_state->zac_buffer, 100, ZAC_FLOOR_POS);
  obj_update(&game_state->zac_buffer, ZAC_SPRITE_ID);
}

void reset_player(GameState* game_state) {
  obj_set_pos(&game_state->zac_buffer, 100, ZAC_FLOOR_POS);
  obj_update(&game_state->zac_buffer, ZAC_SPRITE_ID);
}

void update_player_movement(GameState* game_state) {
  if (keysHeld() & KEY_RIGHT) {
    obj_add_pos(&game_state->zac_buffer, PLAYER_SPEED, 0);
  }

  if (keysHeld() & KEY_LEFT) {
    obj_add_pos(&game_state->zac_buffer, -PLAYER_SPEED, 0);
  }

  if ((keysHeld() & KEY_A) && !game_state->is_jumping) {
    game_state->jump_velocity = PLAYER_JUMP_SPEED;
    game_state->is_jumping = true;
  }

  if (game_state->is_jumping) {
    obj_add_pos(&game_state->zac_buffer, 0, -game_state->jump_velocity);
    game_state->jump_velocity -= GRAVITY;

    if (game_state->player->Y - game_state->jump_velocity >= ZAC_FLOOR_POS) {
      game_state->jump_velocity = 0;
      game_state->is_jumping = false;
      obj_set_pos_y(&game_state->zac_buffer, ZAC_FLOOR_POS);
    }
  }

  game_state->player_collider.min_x = game_state->player->X;
  game_state->player_collider.max_x = game_state->player_collider.min_x + ZAC_WIDTH;
  game_state->player_collider.min_y = game_state->player->Y;
  game_state->player_collider.max_y = game_state->player_collider.min_y + ZAC_HEIGHT;

  // Update Zac's sprite position
  obj_update(&game_state->zac_buffer, ZAC_SPRITE_ID);
}