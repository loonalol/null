#ifndef PLAYER_H 
#define PLAYER_H
#define GL_SILENCE_DEPRECATION
#include "GLFW/glfw3.h"
#include <stdlib.h>
typedef struct {
    float x;
    float y;
    float speed;
} Player;

Player* init_player(float x, float y, float speed);
void move_player(Player* player, int key);
#endif 
