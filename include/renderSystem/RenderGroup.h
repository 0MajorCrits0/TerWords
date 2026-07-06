#pragma once

#include "glad/glad.h"

#include <vector>

class RenderGroup
{
public:
    RenderGroup(bool compressed);
    ~RenderGroup();

    void add(const float* data, std::size_t size);
    void clear();
    void render();

private:
    std::vector<float> elements;
    std::vector<uint32_t> indices;
    bool changed = true;
    bool compressed = false;
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLuint EBO = 0;
};