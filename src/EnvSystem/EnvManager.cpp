#include "EnvSystem/EnvManager.h"
#include "EnvSystem/EnvKeyboard.h"
#include "EnvSystem/EnvWindow.h"

#include "InputMessage.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "Config.h"

void EnvManager::init(InputMessage* input)
{
    EnvWindow* window = new EnvWindow();
    window->init();

    keyboard = new EnvKeyboard();

    this->pocket = new Pocket();
    this->pocket->window = window;
    this->pocket->input = input;
    this->pocket->orthoMatrix = ortho((float)WIDTH, (float)HEIGHT);

    glfwSetWindowUserPointer(window->frame, (void*)pocket);

    glfwSetKeyCallback(window->frame, [](GLFWwindow* window, int key, int, int action, int)
    {
        Pocket* pocket = static_cast<Pocket*>(glfwGetWindowUserPointer(window));
        InputMessage* input = pocket->input;

        if (key < 0 || key >= 512)
            return;

        if (action == GLFW_PRESS || action == GLFW_REPEAT)
            input->curr[key] = true;

        else if (action == GLFW_RELEASE)
            input->curr[key] = false;
    });

    glfwSetFramebufferSizeCallback(window->frame, [](GLFWwindow* window, int width, int height)
    {
        Pocket* pocket = static_cast<Pocket*>(glfwGetWindowUserPointer(window));

        pocket->orthoMatrix = ortho((float)width, (float)height);
        glViewport(0, 0, width, height);
    });
}

mat4 EnvManager::getOrthoMatrix()
{
    return pocket->orthoMatrix;
}

void EnvManager::update()
{
    InputMessage* input = pocket->input;
    this->keyboard->update(input);

    EnvWindow* window = pocket->window;
    window->update();

    if (input->isKeyDown(GLFW_KEY_ESCAPE))
		window->windowSetShouldClose();
}

void EnvManager::deinit()
{
    EnvWindow* window = pocket->window;
    window->deinit();

    delete window;
    delete pocket;
    delete keyboard;
}

bool EnvManager::isWorking()
{
    EnvWindow* window = pocket->window;
    return !glfwWindowShouldClose(window->frame);
}