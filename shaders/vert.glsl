#version 330 core

layout(location = 0) in vec2 position;

uniform vec2 offset;
uniform mat4 orthoMatrix;

void main()
{
    gl_Position = orthoMatrix * vec4(position + offset, 0.0f, 1.0f);
}