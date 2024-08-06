#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "GuiHandler.h"
#include <iostream>
#include <glm/glm.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);

#endif // MAIN_H_INCLUDED
