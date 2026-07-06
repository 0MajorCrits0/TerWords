#include "EnvSystem/EnvWindow.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Config.h"

void EnvWindow::init() {
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


bool EnvWindow::windowShouldClose() const {
    return glfwWindowShouldClose(frame);
}

void EnvWindow::windowSetShouldClose() {
    return glfwSetWindowShouldClose(frame, true);
}

void EnvWindow::update()
{
    glfwSwapBuffers(frame);
    glfwPollEvents();
}

void EnvWindow::clear()
{
    glClearColor(MAINCOLOR, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void EnvWindow::deinit()
{
    glfwDestroyWindow(frame);
    glfwTerminate();
}