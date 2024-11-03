#include "health_bar.h"
#include "constants.h"
#include "obj_utils.h"
#include <gba_sprites.h>

int const HEALTH_SPRITE_WIDTH = 16;
int const NUM_HEARTS = 3;

void init_health_bar() {
  // Initialize the health bar
  OBJATTR buffer;
  buffer.attr0 = OBJ_256_COLOR | OBJ_SHAPE(0);
  buffer.attr1 = OBJ_SIZE(1) | OBJ_ROT_SCALE(2);
  buffer.attr2 = HEART_BASE_TILE_IDX * 2;

  int base_x = FRAME_WIDTH - HEALTH_SPRITE_WIDTH - 2;
  int spacing = HEALTH_SPRITE_WIDTH + 2;
  for (int i = 0; i < NUM_HEARTS; i++) {
    obj_set_pos(&buffer, base_x - i * spacing, 2);
    obj_update(&buffer, HEALTH_BAR_BASE_SPRITE_ID + i);
  }
}

void update_health_bar(int health) {
  for (int i = 0; i < NUM_HEARTS; i++) {
    OBJATTR* heart = &OAM[HEALTH_BAR_BASE_SPRITE_ID + i];
    if (i < health) {
      obj_enable(heart);
    } else {
      obj_disable(heart);
    }
  }
}
