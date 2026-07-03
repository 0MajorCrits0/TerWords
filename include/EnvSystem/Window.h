#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class GLFWwindow;

class Window {
public:
    void init();
    void update();
    void deinit();

    void clear();
    bool windowShouldClose() const;
    void windowSetShouldClose();

    friend class PlayerController;
    friend class EnvironmentManager;
private:
    GLFWwindow* frame = nullptr;
};