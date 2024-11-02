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
#include "physics_obj.h"
#include "random.h"

// This scale is applied to any sprites maked as ROT/SCALE using the first affine matrix.
int const SCALE_X = 256; // .8 fixed point, 0.0 = 0, 0.5 = 128, 1.0 = 256, 1.5 = 384
int const SCALE_Y = 256;

int const BOTTLE_SCALE_X = 384;
int const BOTTLE_SCALE_Y = 384;

int const PUPPY_SCALE_X = 384;
int const PUPPY_SCALE_Y = 384;

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

  // Reserved
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
    void* destination = SCREEN_BASE_BLOCK(9) + x + y * 32 + i * 32;
    *((uint16_t*)destination) = tile_indices;
  }
}

void render_string(int x, int y, char* string) {
  memset((void*)SCREEN_BASE_BLOCK(9), 152, 32 * 32);

  int i = 0;
  while (string[i] != '\0') {
    render_character(x + i * 2, y, string[i]);
    i++;
  }
}

void render_score(char* score_str, int score) {
  memset(score_str, '\0', 50);
  sprintf(score_str, "score %d", score);
  render_string(0, 0, score_str);
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
  
  memset((void*)SCREEN_BASE_BLOCK(9), 28 * 4 - 8, 32 * 32);

  int score = 0;
  int bottle_hits = 0;

  char* score_str = malloc(50);
  memset(score_str, '\0', 50);
  
  render_score(score_str, score);

  REG_BG2CNT = BG_PRIORITY(0) | ROTBG_SIZE_256x256 | CHAR_BASE(2) | SCREEN_BASE(9);
  REG_BG2X = (-2 << 8);
  REG_BG2Y = (-2 << 8);

  REG_BG2PA = 315;
  REG_BG2PB = 0;
  REG_BG2PC = 0;
  REG_BG2PD = 315;

  // Copy the background palette to palette memory and fade in (blocking for 60 frames)
  FadeToPalette(menuPal, 60);

  // Copy spritesheet to memory (tiles, palette)
  CpuSet(gfx_spritesheet_tiles, OBJ_BASE_ADR, gfx_spritesheet_tiles_len / 2);
  CpuSet(gfx_puppy_tiles, OBJ_BASE_ADR + gfx_spritesheet_tiles_len, gfx_puppy_tiles_len / 2);
  CpuSet(gfx_palette, OBJ_COLORS, gfx_palette_len / 2);

  // Disable all OBJs
  obj_disable_all();

  // Enable sprites (1D memory layout)
  REG_DISPCNT |= OBJ_ENABLE | OBJ_1D_MAP | BG2_ENABLE;

  // Game State
  GameState game_state;
  game_state.frame_count = 0;
  game_state.theta = 0xFFFF; // 0x0 - 0xFFFF
  game_state.jump_velocity = 0;
  game_state.is_jumping = false;

  // Olive NPC sprite (32x32@8bpp)
  OBJATTR olive_buffer;
  olive_buffer.attr0 = OBJ_256_COLOR | OBJ_SHAPE(0) | ATTR0_ROTSCALE_DOUBLE;
  olive_buffer.attr1 = OBJ_SIZE(2) | OBJ_ROT_SCALE(2);
  olive_buffer.attr2 = 32 * 2;

  obj_set_pos(&olive_buffer, 120, FRAME_HEIGHT - 40);
  obj_update(&olive_buffer, 4);

  // Initialize the physics world
  init_physics_world(&game_state, 5);

  init_katho(&game_state);
  init_player(&game_state);

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
        score++;
        render_score(score_str, score);
      } else {
        bottle_hits++;

        if (bottle_hits >= 3) {
          // Game over
          // TODO: FadeToBlack(60);
          score = 0;
          bottle_hits = 0;
          render_score(score_str, score);
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
