#include <gba_base.h>
#include <gba_video.h>
#include <gba_systemcalls.h>
#include <gba_interrupt.h>
#include <gba_sprites.h>
#include <gba_dma.h>
#include <gba_input.h>
#include <fade.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"
#include "font.h"
#include "gfx.h"
#include "gfx_palette.h"

#include "constants.h"
#include "obj_utils.h"
#include "math.h"
#include "bouquet.h"
#include "game_state.h"
#include "player.h"
#include "katho.h"
#include "bottle.h"
#include "puppy.h"
#include "physics_obj.h"
#include "random.h"
#include "text.h"
#include "health_bar.h"
#include "game_over.h"

// This scale is applied to any sprites maked as ROT/SCALE using the first affine matrix.
int const SCALE_X = 256; // .8 fixed point, 0.0 = 0, 0.5 = 128, 1.0 = 256, 1.5 = 384
int const SCALE_Y = 256;

int const BOTTLE_SCALE_X = 384;
int const BOTTLE_SCALE_Y = 384;

int const PUPPY_SCALE_X = 384;
int const PUPPY_SCALE_Y = 384;

void render_score(char* score_str, int score) {
  memset(score_str, '\0', 50);
  sprintf(score_str, "score %d", score);
  render_text(0, 0, score_str);
}

int main() {
  // Set up the interrupt handlers
  irqInit();

  // Enable Vblank Interrupt to allow VblankIntrWait
  irqEnable(IRQ_VBLANK);

  // Allow Interrupts
  REG_IME = 1;

  // Set video mode 1 so BG0-BG1 are text mode and BG2 is affine
  REG_DISPCNT = MODE_1 | BG1_ENABLE;

  // Copy the background to memory (tiles, map)
  // 0x6000000 - 0x6000DC0 = 3520 bytes
  CpuSet(menuTiles, (void*)CHAR_BASE_ADR(0), menuTilesLen / 2);

  // 0x6004000 - 0x6004800 = 2048 bytes
  CpuSet(menuMap, (void*)SCREEN_BASE_BLOCK(8), menuMapLen / 2);
  REG_BG1CNT = BG_PRIORITY(1) | TEXTBG_SIZE_256x256 | CHAR_BASE(0) | SCREEN_BASE(8);

  // 0x6008000 - 0x600AA00 = 10752 bytes
  CpuSet(font_tiles, (void*)CHAR_BASE_ADR(2), font_tiles_len / 2);
  
  // Initialize the text screen (BG2, with priority 0)
  init_text();

  init_game_over_screen();

  // Start with "SCORE 0" on the screen.
  char* score_str = malloc(50);
  memset(score_str, '\0', 50);
  render_score(score_str, 0);

  // Copy the background palette to palette memory and fade in (blocking for 60 frames)
  FadeToPalette(menuPal, 60);

  // Copy spritesheet to memory (tiles, palette)
  CpuSet(gfx_spritesheet_tiles, OBJ_BASE_ADR, gfx_spritesheet_tiles_len / 2);
  CpuSet(gfx_puppy_tiles, OBJ_BASE_ADR + gfx_spritesheet_tiles_len, gfx_puppy_tiles_len / 2);
  CpuSet(gfx_palette, OBJ_COLORS, gfx_palette_len / 2);

  // Disable all OBJs
  obj_disable_all();

  // Enable sprites (1D memory layout)
  REG_DISPCNT |= OBJ_ENABLE | OBJ_1D_MAP;

  // Game State
  GameState game_state;
  game_state.score = 0;
  game_state.bottle_hits = 0;
  game_state.frame_count = 0;
  game_state.theta = 0xFFFF; // 0x0 - 0xFFFF
  game_state.jump_velocity = 0;
  game_state.is_jumping = false;

  // Initialize the physics world
  init_physics_world(&game_state, PHYSICS_OBJ_BASE_SPRITE_ID);

  init_katho(&game_state);
  init_player(&game_state);
  init_puppy();
  init_health_bar();

  init_bq_pool(&game_state);
  init_bottle_pool(&game_state);

  // Set the first affine matrix to the identity matrix
  // Note: obj_update calls can overwrite the affine matrix, so it must be reapplied every frame.
  OBJAFFINE* affine_buffer = (OBJAFFINE*)0x07000000;
  obj_affine_identity(&affine_buffer[0]);
  obj_affine_identity(&affine_buffer[1]);
  obj_affine_scale(
    &affine_buffer[2],
    PUPPY_SCALE_X, 
    PUPPY_SCALE_Y
  );

  Xorshift random_state;
  xorshift_init(&random_state, 0x12345678);

  while (true) {
    // Wait for VBlank
    VBlankIntrWait();

    // Scan for key presses
    scanKeys();

    // Launch something every 25 frames
    if (game_state.frame_count % 25 == 0) {
      int choice = xorshift_range(&random_state, 0, 100);
      if (choice < 20) {
        launch_bottle(&game_state);
      } else {
        launch_bq(&game_state);
      }
    }

    // Player movement
    update_player_movement(&game_state);

    // Physics world
    update_physics_world(&game_state);

    // Collision detection
    PhysicsObj* colliding_obj = get_colliding_obj_with_box(
      &game_state,
      &game_state.player_collider
    );
    if (colliding_obj != NULL) {
      // Kill the colliding object
      kill_physics_object(&game_state, colliding_obj);

      if (colliding_obj->type == BOUQUET) {
        game_state.score++;
        render_score(score_str, game_state.score);
      } else {
        game_state.bottle_hits++;
        update_health_bar(HEALTH - game_state.bottle_hits);

        if (game_state.bottle_hits >= HEALTH) {
          // Game over screen, returns when the player presses start
          game_over_screen(game_state.score);

          game_state.score = 0;
          game_state.bottle_hits = 0;
          render_score(score_str, game_state.score);
          update_health_bar(HEALTH);
        }
      }
    }

    // Apply rotation to the first affine matrix
    // This can be used to rotate any sprite constantly.
    if (game_state.frame_count % 3 == 0) {
      game_state.theta -= 0x1200;
    }
    obj_affine_rotate(
      &affine_buffer[0],
      SCALE_X, 
      SCALE_Y,
      game_state.theta
    );
    obj_affine_rotate(
      &affine_buffer[1],
      BOTTLE_SCALE_X, 
      BOTTLE_SCALE_Y,
      game_state.theta
    );

    game_state.frame_count++;
  }
}
