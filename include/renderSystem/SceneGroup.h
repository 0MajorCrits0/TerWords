#pragma once

#include <vector>
#include <glad/glad.h>

class SceneGroup
{
public:
    SceneGroup(bool compressed);
    ~SceneGroup();

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