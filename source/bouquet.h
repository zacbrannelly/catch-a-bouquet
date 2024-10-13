#ifndef BOUQUET_H_
#define BOUQUET_H_

#include <gba_base.h>
#include "constants.h"

typedef struct GameState GameState;

void init_bq_pool(GameState* game_state);
void launch_bq(GameState* game_state);

#endif
