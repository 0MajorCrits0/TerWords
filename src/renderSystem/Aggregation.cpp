#include "RenderSystem/Aggregation.h"

#include <iostream>


Aggregation::Aggregation()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

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

Aggregation::~Aggregation()
{
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void Aggregation::add(const float* data, std::size_t size)
{
    if (!data || size == 0)
        return;

    elements.insert(elements.end(), data, data + size);
    changed = true;
}

void Aggregation::clear()
{
    elements.clear();
    changed = true;
}

void Aggregation::render()
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
        changed = false;
    }

    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(elements.size()));

    glBindVertexArray(0);
}