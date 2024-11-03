#include "puppy.h"
#include "constants.h"
#include "obj_utils.h"

#include <gba_sprites.h>
#include <gba_base.h>

void init_puppy() {
  // Olive NPC sprite (32x32@8bpp)
  OBJATTR olive_buffer;
  olive_buffer.attr0 = OBJ_256_COLOR | OBJ_SHAPE(0) | ATTR0_ROTSCALE_DOUBLE;
  olive_buffer.attr1 = OBJ_SIZE(2) | OBJ_ROT_SCALE(2);
  olive_buffer.attr2 = PUPPY_BASE_TILE_IDX * 2;

  obj_set_pos(&olive_buffer, 120, FRAME_HEIGHT - 40);
  obj_update(&olive_buffer, PUPPY_SPRITE_ID);
}
