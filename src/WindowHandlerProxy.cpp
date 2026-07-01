#include "WindowHandlerProxy.h"
#include "Window.h"
#include "KeyboardHandler.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

void WindowHandlerProxy::init(const Window* window, 
                    const KeyboardHandler* keyboard)
{
    glfwSetWindowUserPointer(window->window, (void*)keyboard);
    glfwSetKeyCallback(window->window, [](GLFWwindow* window, int key, int, int action, int)
    {
        auto keyboard = static_cast<KeyboardHandler*>(glfwGetWindowUserPointer(window));
        if (key >= 0 && key < 512)
        {
            if (action == GLFW_PRESS)
                keyboard->curr[key] = true;
            else if (action == GLFW_RELEASE)
                keyboard->curr[key] = false;
        }
    });
}