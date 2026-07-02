#version 330 core

layout(location = 0) in vec2 position;

uniform mat4 orthoMatrix;

void main()
{
    gl_Position = orthoMatrix * vec4(position, 0.0f, 1.0f);
}