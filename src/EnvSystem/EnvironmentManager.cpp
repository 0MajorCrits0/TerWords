#include "EnvSystem/EnvironmentManager.h"
#include "EnvSystem/Window.h"
#include "EnvSystem/Keyboard.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Config.h"

void EnvironmentManager::init(Keyboard* keyboard)
{
    Pocket* pocket = new Pocket();

    Window* window = new Window();
    window->init();

    pocket->window = window;
    pocket->keyboard = keyboard;

    glfwSetWindowUserPointer(window->frame, (void*)pocket);

    glfwSetKeyCallback(window->frame, [](GLFWwindow* window, int key, int, int action, int)
    {
        auto pocket = static_cast<Pocket*>(glfwGetWindowUserPointer(window));
        Keyboard* keyboard = pocket->keyboard;

        if (key < 0 || key >= 512)
            return;

        if (action == GLFW_PRESS || action == GLFW_REPEAT)
            keyboard->curr[key] = true;

        else if (action == GLFW_RELEASE)
            keyboard->curr[key] = false;
    });

    glfwSetFramebufferSizeCallback(window->frame, [](GLFWwindow* window, int width, int height)
    {
        auto pocket = static_cast<Pocket*>(glfwGetWindowUserPointer(window));

        pocket->orthoMatrix = ortho((float)width, (float)height);
        glViewport(0, 0, width, height);
    });

    pocket->orthoMatrix = ortho((float)WIDTH, (float)HEIGHT);
    this->pocket = pocket;
}

mat4 EnvironmentManager::getOrthoMatrix()
{
    return pocket->orthoMatrix;
}

void EnvironmentManager::update()
{
    Window* window = pocket->window;
    window->update();

    Keyboard* keyboard = pocket->keyboard;
    keyboard->update();

    if (keyboard->isKeyDown(GLFW_KEY_ESCAPE))
		window->windowSetShouldClose();
}

void EnvironmentManager::deinit()
{
    Window* window = pocket->window;
    window->deinit();

    delete window;
    delete pocket;
}

bool EnvironmentManager::isWorking()
{
    Window* window = pocket->window;
    return !glfwWindowShouldClose(window->frame);
}