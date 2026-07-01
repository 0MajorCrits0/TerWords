#include "RenderSystem/Program.h"
#include "Config.h"

#include <fstream>
#include <sstream>

#include <glad/glad.h>

std::string readFile(const std::string& path);

Program::Program(const std::string& vertexPath, const std::string& fragmentPath)
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char* vertexCode = readFile(SHADERPATH + vertexPath).c_str();
    glShaderSource(vertexShader, 1, &vertexCode, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char* fragmentCode = readFile(SHADERPATH + fragmentPath).c_str();
    glShaderSource(fragmentShader, 1, &fragmentCode, nullptr);
    glCompileShader(fragmentShader);

    id = glCreateProgram();

    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);

    glLinkProgram(id);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Program::~Program()
{
    glDeleteProgram(id);
}

void Program::use() const
{
    glUseProgram(id);
}

std::string readFile(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open())
        return {};

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}