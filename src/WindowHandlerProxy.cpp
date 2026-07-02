#include "WindowHandlerProxy.h"
#include "Window.h"
#include "KeyboardHandler.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Config.h"

struct Pocket
{
    Window* window;
    KeyboardHandler* keyboard;
    WindowHandlerProxy* proxy;
};

void WindowHandlerProxy::init(Window* window, KeyboardHandler* keyboard)
{

    Pocket* pocket = new Pocket();
    pocket->window = window;
    pocket->keyboard = keyboard;
    pocket->proxy = this;
    
    this->orthoMatrix = ortho((float)WIDTH, (float)HEIGHT);

    glfwSetWindowUserPointer(window->window, (void*)pocket);
    glfwSetKeyCallback(window->window, [](GLFWwindow* window, int key, int, int action, int)
    {
        auto pocket = static_cast<Pocket*>(glfwGetWindowUserPointer(window));
        KeyboardHandler* keyboard = pocket->keyboard;
        if (key >= 0 && key < 512)
        {
            if (action == GLFW_PRESS)
                keyboard->curr[key] = true;
            else if (action == GLFW_RELEASE)
                keyboard->curr[key] = false;
        }
    });

    glfwSetFramebufferSizeCallback(window->window, [](GLFWwindow* window, int width, int height)
    {
        auto pocket = static_cast<Pocket*>(glfwGetWindowUserPointer(window));
        WindowHandlerProxy* proxy = pocket->proxy;

        proxy->orthoMatrix = ortho((float)width, (float)height);
        glViewport(0, 0, width, height);
    });
}

mat4 WindowHandlerProxy::getOrthoMatrix()
{
    return orthoMatrix;
}