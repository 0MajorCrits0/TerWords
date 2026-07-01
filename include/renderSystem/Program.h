#pragma once

#include <string>

class Program
{
public:
    Program(const std::string& vertexPath, const std::string& fragmentPath);
    void use() const;
    ~Program();
    
private:
    unsigned int id;
};