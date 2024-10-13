#ifndef MATH_H
#define MATH_H

#include "gba_base.h"

extern s16 g_sin_lut[514];

//! Look-up a sine value (2&#960; = 0x10000)
/*! \param theta Angle in [0,FFFFh] range
*	 \return .12f sine value
*/
inline s32 lu_sin(u16 theta) {
  return g_sin_lut[(theta >> 7) & 0x1FF];
}

//! Look-up a cosine value (2&#960; = 0x10000)
/*! \param theta Angle in [0,FFFFh] range
*	 \return .12f cosine value
*/
inline s32 lu_cos(u16 theta) {
  return g_sin_lut[((theta >> 7) + 128) & 0x1FF];
}

inline s32 clamp(s32 val, s32 min, s32 max) {
  if(val < min)
    return min;
  if(val > max)
    return max;
  return val;
}

#endif // MATH_H
