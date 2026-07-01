#pragma once

#include <vector>
#include <cstddef>
#include <glad/glad.h>

class Aggregation
{
public:
    Aggregation();
    ~Aggregation();

    void add(const float* data, std::size_t size);
    void clear();
    void render();

private:
    std::vector<float> elements;
    bool changed = true;
    GLuint VAO = 0;
    GLuint VBO = 0;
};