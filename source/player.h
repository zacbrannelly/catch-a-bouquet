#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct GameState GameState;

void init_player(GameState* game_state);
void update_player_movement(GameState* game_state);

#endif // PLAYER_H_