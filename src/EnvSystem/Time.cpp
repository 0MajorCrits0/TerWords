#include "EnvSystem/Time.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

void Time::update() {
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }

float Time::getDeltaTime() {
    return deltaTime;
}