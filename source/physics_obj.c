#include "physics_obj.h"
#include "constants.h"
#include "obj_utils.h"
#include "game_state.h"
#include "math.h"

void init_physics_world(GameState* game_state, uint8_t obj_id_base) {
  PhysicsWorld* world = &game_state->physics_world;
  world->obj_id_base = obj_id_base;
  world->gravity = GRAVITY;
  world->objs_allocated = 0;
  for (int i = 0; i < MAX_PHYSICS_OBJS; i++) {
    world->pool[i].x = FRAME_WIDTH;
    world->pool[i].y = FRAME_HEIGHT;
    world->pool[i].velocity_x = 0;
    world->pool[i].velocity_y = 0;
    world->pool[i].enabled = false;
    world->pool[i].type = EMPTY;
  }
}

void init_physics_object_pool(
  GameState* game_state,
  OBJATTR* obj_buffer,
  PhysicsObjType type,
  Collider* collider,
  ColliderType collider_type,
  int num_objs
) {
  PhysicsWorld* world = &game_state->physics_world;
  for (int i = 0; i < num_objs; i++) {
    if (world->objs_allocated >= MAX_PHYSICS_OBJS) {
      break;
    }
    PhysicsObj* obj = &world->pool[world->objs_allocated];
    obj->type = type;
    obj->collider = *collider;
    obj->collider_type = collider_type;
    obj->obj_id = world->obj_id_base + world->objs_allocated;

    // Apply position to the sprite's OAM memory.
    obj_set_pos(obj_buffer, obj->x, obj->y);
    obj_update(obj_buffer, obj->obj_id);
    world->objs_allocated++;
  }
}

PhysicsObj* spawn_physics_object(
  GameState* game_state,
  PhysicsObjType type,
  int x,
  int y,
  int velocity_x,
  int velocity_y
) {
  PhysicsWorld* world = &game_state->physics_world;
  for (int i = 0; i < MAX_PHYSICS_OBJS; i++) {
    PhysicsObj* obj = &world->pool[i];
    if (obj->enabled) continue;
    if (obj->type != type) continue;

    obj->x = x;
    obj->y = y;
    obj->velocity_x = velocity_x;
    obj->velocity_y = velocity_y;
    obj->enabled = true;

    // Apply position to the sprite's OAM memory.
    OBJATTR* obj_buffer = &OAM[obj->obj_id];
    obj_set_pos(obj_buffer, obj->x, obj->y);

    return obj;
  }
  return NULL;
}

void kill_physics_object(GameState* game_state, PhysicsObj* obj) {
  obj->x = FRAME_WIDTH;
  obj->y = FRAME_HEIGHT;
  obj->velocity_x = 0;
  obj->velocity_y = 0;
  obj->enabled = false;

  // Apply position to the sprite's OAM memory.
  OBJATTR* obj_buffer = &OAM[obj->obj_id];
  obj_set_pos(obj_buffer, obj->x, obj->y);
}

void update_physics_world(GameState* game_state) {
  PhysicsWorld* world = &game_state->physics_world;
  if (game_state->frame_count % 3 == 0) {
    for (int i = 0; i < 40; i++) {
      PhysicsObj* obj = &world->pool[i];
      if (!obj->enabled) continue;

      // Apply physics to the sprite.
      obj->x += obj->velocity_x;
      obj->y += obj->velocity_y;
      obj->velocity_y += world->gravity;

      // Disable the sprite if it hits the floor.
      if (obj->y >= FRAME_HEIGHT - 16) {
        kill_physics_object(game_state, obj);
        continue;
      }

      // Apply position to the sprite's OAM memory.
      OBJATTR* obj_buffer = &OAM[obj->obj_id];
      obj_set_pos(obj_buffer, obj->x, obj->y);
    }
  }
}

bool check_collision_boxes(BoxCollider* a, BoxCollider* b) {
  if (a->min_x > b->max_x || a->max_x < b->min_x) {
    return false;
  }

  if (a->min_y > b->max_y || a->max_y < b->min_y) {
    return false;
  }

  return true;
}

bool check_collision_box_and_circle(BoxCollider* a, CircleCollider* b) {
  int closest_x = clamp(b->center_x, a->min_x, a->max_x);
  int closest_y = clamp(b->center_y, a->min_y, a->max_y);

  int distance_x = b->center_x - closest_x;
  int distance_y = b->center_y - closest_y;

  int distance_squared = distance_x * distance_x + distance_y * distance_y;
  return distance_squared < b->radius * b->radius;
}

bool check_collision_circles(CircleCollider* a, CircleCollider* b) {
  int distance_x = a->center_x - b->center_x;
  int distance_y = a->center_y - b->center_y;

  int distance_squared = distance_x * distance_x + distance_y * distance_y;
  int radius_sum = a->radius + b->radius;
  return distance_squared < radius_sum * radius_sum;
}

PhysicsObj* get_colliding_obj_with_box(GameState* game_state, BoxCollider* collider) {
  PhysicsWorld* world = &game_state->physics_world;
  for (int i = 0; i < MAX_PHYSICS_OBJS; i++) {
    PhysicsObj* obj = &world->pool[i];
    if (!obj->enabled) continue;

    switch (obj->collider_type) {
      case BOX:
        BoxCollider box = obj->collider.box;
        box.min_x += obj->x;
        box.max_x += obj->x;
        box.min_y += obj->y;
        box.max_y += obj->y;
        if (check_collision_boxes(collider, &box)) {
          return obj;
        }
        break;
      case CIRCLE:
        CircleCollider circle = obj->collider.circle;
        circle.center_x += obj->x;
        circle.center_y += obj->y;
        if (check_collision_box_and_circle(collider, &circle)) {
          return obj;
        }
        break;
      default:
        break;
    }
  }
  return NULL;
}
