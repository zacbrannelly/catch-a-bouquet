#ifndef PHYSICS_OBJ_H_
#define PHYSICS_OBJ_H_

#include <gba_base.h>
#include <gba_sprites.h>
#include "constants.h"

typedef struct GameState GameState;

typedef enum ColliderType {
  CIRCLE = 0,
  RECTANGLE = 1
} ColliderType;

typedef struct BoxCollider {
  int x;
  int y;
  int width;
  int height;
} ALIGN(4) BoxCollider;

typedef struct CircleCollider {
  int x;
  int y;
  int radius;
} ALIGN(4) CircleCollider;

typedef union Collider {
  BoxCollider box;
  CircleCollider circle;
} Collider;

typedef enum PhysicsObjType {
  EMPTY = 0,
  PLAYER = 1,
  BOTTLE = 2,
  BOUQUET = 3
} PhysicsObjType;

typedef struct PhysicsObj {
  int x;
  int y;
  int velocity_x;
  int velocity_y;
  int obj_id;
  bool enabled;
  PhysicsObjType type;
  Collider collider;
  ColliderType collider_type;
} ALIGN(4) PhysicsObj;

typedef struct PhysicsWorld {
  int gravity;
  int objs_allocated;
  uint8_t obj_id_base;
  PhysicsObj pool[MAX_PHYSICS_OBJS];
} ALIGN(4) PhysicsWorld;

/**
 * Initializes the physics world.
 */
void init_physics_world(GameState* game_state, uint8_t obj_id_base);

/**
 * Initializes a pool of physics objects.
 */
void init_physics_object_pool(
  GameState* game_state,
  OBJATTR* obj_buffer,
  PhysicsObjType type,
  int num_objs
);

/**
 * Spawns a physics object.
 */
PhysicsObj* spawn_physics_object(
  GameState* game_state,
  PhysicsObjType type,
  int x,
  int y,
  int velocity_x,
  int velocity_y
);

/**
 * Updates the physics world.
 */
void update_physics_world(GameState* game_state);

#endif // PHYSICS_OBJ_H_
