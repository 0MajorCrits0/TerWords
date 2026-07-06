#pragma once

#include "MathObjects.h"

#include <string>

class RenderProgram
{
public:
    RenderProgram(const std::string& vertexPath, const std::string& fragmentPath);
    void use() const;
    void setUniform(std::string name, float value);
    void setUniform(std::string name, vec3 value);
    void setUniform(std::string name, mat4 value);
    ~RenderProgram();
    
private:
    unsigned int id;
};