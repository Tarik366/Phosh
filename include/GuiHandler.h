#ifndef GUIHANDLER_H
#define GUIHANDLER_H
#define GLFW_DLL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <iostream>

void drawRect(int x, int y, int w, int h, float color[4]);

void drawText(int x, int y, float textSize, std::string textString);

#endif // GUIHANDLER_H
