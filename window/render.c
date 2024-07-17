#define GL_SILENCE_DEPRECATION
#include "GLFW/glfw3.h"
#include <OpenGL/gl.h>
#include <stdio.h>
GLFWwindow* window;
void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
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
    glEnable(GL_DEPTH_TEST);
}
void render() {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glClearColor(0.7f, 0.7f, 1.0f, 1.0f);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
void cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
