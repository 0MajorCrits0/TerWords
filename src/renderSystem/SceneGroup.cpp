#include "RenderSystem/SceneGroup.h"
#include "glad/glad.h"

SceneGroup::SceneGroup(bool compressed)
{
    this->compressed = compressed;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(
        0,
        2,
        GL_FLOAT,
        GL_FALSE,
        2 * sizeof(float),
        (void*)0
    );

    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

SceneGroup::~SceneGroup()
{
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}

void SceneGroup::add(const float* data, std::size_t size)
{
    if (!data || size == 0)
        return;

    elements.insert(elements.end(), data, data + size);

    std::uint32_t base = 2 * indices.size() / 3;
    for (std::uint32_t i = 0; i < size / 8; ++i)
    {
        std::uint32_t v = base + i * 4;

        indices.push_back(v + 0);
        indices.push_back(v + 1);
        indices.push_back(v + 2);

        indices.push_back(v + 1);
        indices.push_back(v + 2);
        indices.push_back(v + 3);
    }
    changed = true;
}

void SceneGroup::clear()
{
    elements.clear();
    indices.clear();
    changed = true;
}

void SceneGroup::render()
{
    if (elements.empty())
        return;

    glBindVertexArray(VAO);

    if (changed)
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(
            GL_ARRAY_BUFFER,
            elements.size() * sizeof(float),
            elements.data(),
            GL_DYNAMIC_DRAW
        );

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(
            GL_ELEMENT_ARRAY_BUFFER,
            indices.size() * sizeof(uint32_t),
            indices.data(),
            GL_DYNAMIC_DRAW
        );
        changed = false;
    }

    if (compressed) 
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    else
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(elements.size()) / 2);

    glBindVertexArray(0);
}