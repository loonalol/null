#ifndef RENDERER_H
#define RENDERER_H

#include "GLFW/glfw3.h"
#include <OpenGL/gl.h>

extern GLFWwindow* window;

void init();
void render();
void cleanup();

#endif 