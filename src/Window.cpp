#include "Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Config.h"

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


bool Window::windowShouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::windowSetShouldClose() {
    return glfwSetWindowShouldClose(window, true);
}

void Window::update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::clear()
{
    glClearColor(MAINCOLOR, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}