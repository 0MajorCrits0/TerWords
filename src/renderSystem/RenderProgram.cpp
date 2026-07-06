#include "RenderSystem/RenderProgram.h"

#include "glad/glad.h"

#include <iostream>
#include <fstream>
#include <sstream>

std::string readFile(const std::string& path);

RenderProgram::RenderProgram(const std::string& vertexPath, const std::string& fragmentPath)
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    std::string v = readFile(SHADER_PATH + vertexPath);
    const char* vertexCode = v.c_str();
    glShaderSource(vertexShader, 1, &vertexCode, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string f = readFile(SHADER_PATH + fragmentPath);
    const char* fragmentCode = f.c_str();
    glShaderSource(fragmentShader, 1, &fragmentCode, nullptr);
    glCompileShader(fragmentShader);

    id = glCreateProgram();

    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);

    glLinkProgram(id);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    
}

RenderProgram::~RenderProgram()
{
    glDeleteProgram(id);
}

void RenderProgram::use() const
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

void RenderProgram::setUniform(std::string name, float value)
{
    GLint location = glGetUniformLocation(id, name.c_str());
    glUniform1f(location, value);
}

void RenderProgram::setUniform(std::string name, vec3 value)
{
    GLint location = glGetUniformLocation(id, name.c_str());
    glUniform3f(location, value.x, value.y, value.z);
}

void RenderProgram::setUniform(std::string name, mat4 value)
{
    GLint location = glGetUniformLocation(id, name.c_str());  
    glUniformMatrix4fv(location, 1, GL_FALSE, &value.m[0][0]);
}