#ifndef PHYSICS_OBJ_H_
#define PHYSICS_OBJ_H_

#include <gba_base.h>
#include <gba_sprites.h>
#include "constants.h"

typedef struct GameState GameState;

typedef enum ColliderType {
  NONE = 0,
  CIRCLE = 1,
  BOX = 2
} ColliderType;

typedef struct BoxCollider {
  int min_x, max_x;
  int min_y, max_y;
} ALIGN(4) BoxCollider;

typedef struct CircleCollider {
  int center_x;
  int center_y;
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
  Collider* collider,
  ColliderType collider_type,
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
 * Kills a physics object.
 */
void kill_physics_object(GameState* game_state, PhysicsObj* obj);

/**
 * Updates the physics world.
 */
void update_physics_world(GameState* game_state);

PhysicsObj* get_colliding_obj_with_box(GameState* game_state, BoxCollider* collider);

#endif // PHYSICS_OBJ_H_
