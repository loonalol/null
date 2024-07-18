#include "block.h"
void render_square() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.75f, 0.75f); 
    glVertex2f(0.95f, 0.75f); 
    glVertex2f(0.95f, 0.95f); 
    glVertex2f(0.75f, 0.95f); 

    glEnd();
}
