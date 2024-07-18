#define GL_SILENCE_DEPRECATION
#include "GLFW/glfw3.h"
#include <OpenGL/gl.h>
#include <stdio.h>
#include "../libs/block.hpp"
#include "../libs/player.hpp"
#include <Kernel/math.h>

GLFWwindow* window;
Player* player;

void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        move_player(player, key);
    }
}

void setup_3d() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float fov = 45.0f;
    float aspect = 800.0f / 600.0f;
    float near = 0.1f;
    float far = 100.0f;
    float top = near * tanf(fov * M_PI / 360.0f);
    float bottom = -top;
    float right = top * aspect;
    float left = -right;

    glFrustum(left, right, bottom, top, near, far);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void init() {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }
    window = glfwCreateWindow(800, 600, "main", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    setup_3d();
    player = init_player(0.0f, 0.0f, 0.05f);
    if (!player) {
        fprintf(stderr, "Failed to initialize player\n");
        glfwTerminate();
        return;
    }
}

void render() {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f);
        glTranslatef(player->x, player->y, 0.0f);
        render_cube();
        glClearColor(0.7f, 0.7f, 1.0f, 1.0f);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void cleanup() {
    free(player);
    glfwDestroyWindow(window);
    glfwTerminate();
}
