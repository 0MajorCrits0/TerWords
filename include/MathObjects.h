#pragma once

#include <cmath>

typedef struct vec2
{
    float x, y;

    vec2 operator+() const;
    vec2 operator-() const;

    vec2 operator+(const vec2& v) const;
    vec2 operator-(const vec2& v) const;

    vec2 operator*(float s) const;
    vec2 operator/(float s) const;

    vec2& operator+=(const vec2& v);
    vec2& operator-=(const vec2& v);

    vec2& operator*=(float s);
    vec2& operator/=(float s);

    bool operator==(const vec2& v) const;
    bool operator!=(const vec2& v) const;
};

using Vec2 = vec2;
using Vector2 = vec2;

struct vec3
{
    float x, y, z;

    vec3 operator+() const;
    vec3 operator-() const;

    vec3 operator+(const vec3& v) const;
    vec3 operator-(const vec3& v) const;

    vec3 operator*(float s) const;
    vec3 operator/(float s) const;

    vec3& operator+=(const vec3& v);
    vec3& operator-=(const vec3& v);

    vec3& operator*=(float s);
    vec3& operator/=(float s);

    bool operator==(const vec3& v) const;
    bool operator!=(const vec3& v) const;
};

using Vec3 = vec3;
using Vector3 = vec3;

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

inline vec3 normalize(vec3 vec)
{
    float length = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    vec.x /= length;
    vec.y /= length;
    vec.z /= length;
    return vec;
}

inline vec2 normalize(vec2 vec)
{
    float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);
    vec.x /= length;
    vec.y /= length;
    return vec;
}