#include "Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

Window::Window() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

     
    GLFWwindow* window = glfwCreateWindow(800, 600, "TerWords", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0, 0, 800, 600);

    this->window = window;
}


bool Window::windowShouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::windowSetShouldClose() {
    return glfwSetWindowShouldClose(window, true);
}

void Window::update()
{
    glClearColor(0.1f, 0.1f, 0.35f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}