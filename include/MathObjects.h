#pragma once

typedef struct 
{
    float x, y, z;
} vec3, Vec3, Vector3;

typedef struct 

{
    float x, y;
} vec2, Vec2, Vector2;

typedef struct 
{
    float m[4][4];
} mat4, Mat4, Matrix4;

inline mat4 ortho(float width, float height)
{
    mat4 m{};

    float aspect = width / height;

    if (aspect >= 1.0f)
    {
        m.m[0][0] = 1.0f / aspect;
        m.m[1][1] = 1.0f;
    }
    else
    {
        m.m[0][0] = 1.0f;
        m.m[1][1] = aspect;
    }

    m.m[2][2] = 1.0f;
    m.m[3][3] = 1.0f;

    return m;
}