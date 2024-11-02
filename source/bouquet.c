#include "bouquet.h"
#include <gba_sprites.h>
#include "obj_utils.h"
#include "game_state.h"
#include "random.h"
#include "physics_obj.h"

#define BQ_SPRITE_POOL_SIZE 10

int const BQ_SPAWN_X = 30 - 8;
int const BQ_SPAWN_Y = FRAME_HEIGHT - 32 - 16;

int const BQ_MIN_SPEED_X = 4;
int const BQ_MAX_SPEED_X = 9;
int const BQ_MIN_SPEED_Y = 8;
int const BQ_MAX_SPEED_Y = 14;

static Xorshift bq_random_state;

void init_bq_pool(GameState* game_state) {
  // Bouquet NPC sprite (16x16@8bpp)
  OBJATTR bq_buffer;
  bq_buffer.attr0 = OBJ_256_COLOR | OBJ_SHAPE(0) | ATTR0_ROTSCALE_DOUBLE;
  bq_buffer.attr1 = OBJ_SIZE(1);
  bq_buffer.attr2 = BQ_BASE_TILE_IDX * 2;

  // Initialize a pool of 40 bouquet sprites
  Collider bq_collider;
  bq_collider.circle.center_x = 16;
  bq_collider.circle.center_y = 16;
  bq_collider.circle.radius = 4;
  init_physics_object_pool(
    game_state,
    &bq_buffer,
    BOUQUET,
    &bq_collider,
    CIRCLE,
    BQ_SPRITE_POOL_SIZE
  );

  // Initialize random number generator
  xorshift_init(&bq_random_state, 0x12345678);
}

void launch_bq(GameState* game_state) {
  // Calculate random launch speed for the bouquet
  int bq_launch_speed_x = xorshift_range(&bq_random_state, BQ_MIN_SPEED_X, BQ_MAX_SPEED_X);
  int bq_launch_speed_y = xorshift_range(&bq_random_state, BQ_MIN_SPEED_Y, BQ_MAX_SPEED_Y);

  spawn_physics_object(
    game_state,
    BOUQUET,
    BQ_SPAWN_X,
    BQ_SPAWN_Y,
    bq_launch_speed_x,
    -bq_launch_speed_y
  );
}
