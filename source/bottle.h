#ifndef BOTTLE_H_
#define BOTTLE_H_

#include <gba_base.h>
#include "constants.h"

typedef struct GameState GameState;

void init_bottle_pool(GameState* game_state);
void reset_bottle_pool(GameState* game_state);
void launch_bottle(GameState* game_state);
#endif
