#ifndef OBJ_UTILS_H
#define OBJ_UTILS_H

#include <gba_base.h>
#include <gba_sprites.h>
#include <gba_systemcalls.h>
#include "math.h"

inline void obj_affine_identity(OBJAFFINE* obj_affine) {
  obj_affine->pa = 1 << 8;
  obj_affine->pb = 0;
  obj_affine->pc = 0;
  obj_affine->pd = 1 << 8;
}

inline void obj_affine_rotate(OBJAFFINE *oaff, int sx, int sy, u32 alpha)
{
  int ss = lu_sin(alpha);
  int cc = lu_cos(alpha);

  oaff->pa = (cc * sx)  >> 12;
  oaff->pb = (-ss * sx) >> 12;
  oaff->pc = (ss * sy)  >> 12;
  oaff->pd = (cc * sy)  >> 12;
}

inline void obj_set_pos_x(OBJATTR* obj, u16 x) {
  obj->attr1 = (obj->attr1 & 0xFE00) | (x & 0x1FF);
}

inline void obj_set_pos_y(OBJATTR* obj, u8 y) {
  obj->attr0 = (obj->attr0 & 0xFF00) | y;
}

inline void obj_set_pos(OBJATTR* obj, u16 x, u8 y) {
  obj_set_pos_x(obj, x);
  obj_set_pos_y(obj, y);
}

inline void obj_add_pos(OBJATTR* obj, s16 dx, s8 dy) {
  obj_set_pos_x(obj, (obj->attr1 & 0x1FF) + dx);
  obj_set_pos_y(obj, (obj->attr0 & 0xFF) + dy);
}

inline void obj_update(OBJATTR* buffer, u8 obj_id) {
  CpuSet(buffer, &OAM[obj_id], sizeof(OBJATTR) / 2);
}

void obj_disable_all();

#endif // OBJ_UTILS_H
