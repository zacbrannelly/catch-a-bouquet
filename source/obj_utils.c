#include "obj_utils.h"

void obj_disable_all() {
  OBJATTR obj_buffers[128];
  for (u8 i = 0; i < 128; i++) {
    obj_buffers[i].attr0 = OBJ_DISABLE;
  }
  CpuSet(obj_buffers, OAM, sizeof(obj_buffers) / 2);
}
