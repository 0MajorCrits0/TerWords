#include "EnvSystem/EnvTime.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

void EnvTime::update() {
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }

float EnvTime::getDeltaTime() {
    return deltaTime;
}