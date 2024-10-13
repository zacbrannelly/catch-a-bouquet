#include "bouquet.h"
#include <gba_sprites.h>
#include "obj_utils.h"
#include "game_state.h"
#include "random.h"
#include "physics_obj.h"

#define BOTTLE_SPRITE_POOL_SIZE 5

int const BOTTLE_SPAWN_X = 30 - 8;
int const BOTTLE_SPAWN_Y = FRAME_HEIGHT - 32 - 16;

int const BOTTLE_MIN_SPEED_X = 4;
int const BOTTLE_MAX_SPEED_X = 9;
int const BOTTLE_MIN_SPEED_Y = 8;
int const BOTTLE_MAX_SPEED_Y = 14;

static Xorshift bottle_random_state;

void init_bottle_pool(GameState* game_state) {
  // Bottle NPC sprite (16x32@8bpp)
  OBJATTR bottle_buffer;
  bottle_buffer.attr0 = OBJ_256_COLOR | OBJ_SHAPE(2) | ATTR0_ROTSCALE_DOUBLE;
  bottle_buffer.attr1 = OBJ_SIZE(2) | OBJ_ROT_SCALE(1);
  bottle_buffer.attr2 = BOTTLE_BASE_TILE_IDX * 2;

  // Initialize a pool of bottle sprites
  Collider bottle_collider;
  bottle_collider.circle.center_x = 16;
  bottle_collider.circle.center_y = 32;
  init_physics_object_pool(
    game_state,
    &bottle_buffer,
    BOTTLE,
    &bottle_collider,
    CIRCLE,
    BOTTLE_SPRITE_POOL_SIZE
  );

  // Initialize random number generator
  xorshift_init(&bottle_random_state, 0x12345678);
}

void launch_bottle(GameState* game_state) {
  // Calculate random launch speed for the bouquet
  int bottle_launch_speed_x = xorshift_range(&bottle_random_state, BOTTLE_MIN_SPEED_X, BOTTLE_MAX_SPEED_X);
  int bottle_launch_speed_y = xorshift_range(&bottle_random_state, BOTTLE_MIN_SPEED_Y, BOTTLE_MAX_SPEED_Y);

  spawn_physics_object(
    game_state,
    BOTTLE,
    BOTTLE_SPAWN_X,
    BOTTLE_SPAWN_Y,
    bottle_launch_speed_x,
    -bottle_launch_speed_y
  );
}
