#pragma once

#include <string>
#include "MathObjects.h"

class Program
{
public:
    Program(const std::string& vertexPath, const std::string& fragmentPath);
    void use() const;
    void setUniform(std::string name, float value);
    void setUniform(std::string name, vec3 value);
    void setUniform(std::string name, mat4 value);
    ~Program();
    
private:
    unsigned int id;
};