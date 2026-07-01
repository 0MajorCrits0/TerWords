#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class GLFWwindow;

class Window {
public:
    Window();
    bool windowShouldClose();
    void windowSetShouldClose();
    void update();
    ~Window();

    friend class WindowHandlerProxy;
private:
    GLFWwindow* window = nullptr;
};