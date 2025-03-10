#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <gba_base.h>
#include "constants.h"
#include "bouquet.h"
#include "physics_obj.h"

typedef struct GameState {
  int frame_count;
  int theta;
  int jump_velocity;
  bool is_jumping;
  int score;
  int bottle_hits;
  OBJATTR zac_buffer;
  OBJATTR katho_buffer;
  Sprite* player;
  BoxCollider player_collider;
  PhysicsWorld physics_world;
} ALIGN(4) GameState;

#endif // GAME_STATE_H
