#include "EnvSystem/Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Config.h"

void Window::init() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
     
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "TerWords", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0, 0, WIDTH, HEIGHT);

    this->frame = window;
}


bool Window::windowShouldClose() const {
    return glfwWindowShouldClose(frame);
}

void Window::windowSetShouldClose() {
    return glfwSetWindowShouldClose(frame, true);
}

void Window::update()
{
    glfwSwapBuffers(frame);
    glfwPollEvents();
}

void Window::clear()
{
    glClearColor(MAINCOLOR, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::deinit()
{
    glfwDestroyWindow(frame);
    glfwTerminate();
}