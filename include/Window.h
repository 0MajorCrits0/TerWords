#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "MathObjects.h"

class GLFWwindow;

class Window {
public:
    Window();
    bool windowShouldClose() const;
    void windowSetShouldClose();
    void update();
    void clear();
    ~Window();

    friend class WindowHandlerProxy;
private:
    GLFWwindow* window = nullptr;
};