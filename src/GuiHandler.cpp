#include "GuiHandler.h"


void drawRect(int x, int y, int w, int h, float color[4]) {

    glEnable(GL_SCISSOR_TEST);
    glScissor(x, y, w, h);
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT);
    // Remember to disable scissor test, or, perhaps reset the scissor rectangle:
    glDisable(GL_SCISSOR_TEST);
}

void drawText(int x, int y, float textSize) {

}
