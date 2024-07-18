extern "C"
#include "../libs/player.hpp"
#include <GLFW/glfw3.h>
#include <stdlib.h>

Player* init_player(float x, float y, float speed) {
    Player* player = (Player*)malloc(sizeof(Player));
    if (player) {
        player->x = x;
        player->y = y;
        player->speed = speed;
    }
    return player;
}

void move_player(Player* player, int key) {
    if (!player) return;

    switch (key) {
        case GLFW_KEY_W:
            player->y += player->speed;
            break;
        case GLFW_KEY_S:
            player->y -= player->speed;
            break;
        case GLFW_KEY_A:
            player->x -= player->speed;
            break;
        case GLFW_KEY_D:
            player->x += player->speed;
            break;
        default:
            break;
    }
}
