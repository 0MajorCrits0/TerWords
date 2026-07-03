#include "MathObjects.h"

vec2 vec2::operator+() const
{
    return *this;
}

vec2 vec2::operator-() const
{
    return {-x, -y};
}

vec2 vec2::operator+(const vec2& v) const
{
    return {x + v.x, y + v.y};
}

vec2 vec2::operator-(const vec2& v) const
{
    return {x - v.x, y - v.y};
}

vec2 vec2::operator*(float s) const
{
    return {x * s, y * s};
}

vec2 vec2::operator/(float s) const
{
    return {x / s, y / s};
}

vec2& vec2::operator+=(const vec2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

vec2& vec2::operator-=(const vec2& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

vec2& vec2::operator*=(float s)
{
    x *= s;
    y *= s;
    return *this;
}

vec2& vec2::operator/=(float s)
{
    x /= s;
    y /= s;
    return *this;
}

bool vec2::operator==(const vec2& v) const
{
    return x == v.x && y == v.y;
}

bool vec2::operator!=(const vec2& v) const
{
    return !(*this == v);
}

vec2 operator*(float s, const vec2& v)
{
    return v * s;
}

vec3 vec3::operator+() const
{
    return *this;
}

vec3 vec3::operator-() const
{
    return {-x, -y, -z};
}

vec3 vec3::operator+(const vec3& v) const
{
    return {x + v.x, y + v.y, z + v.z};
}

vec3 vec3::operator-(const vec3& v) const
{
    return {x - v.x, y - v.y, z - v.z};
}

vec3 vec3::operator*(float s) const
{
    return {x * s, y * s, z * s};
}

vec3 vec3::operator/(float s) const
{
    return {x / s, y / s, z / s};
}

vec3& vec3::operator+=(const vec3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

vec3& vec3::operator-=(const vec3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

vec3& vec3::operator*=(float s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

vec3& vec3::operator/=(float s)
{
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

bool vec3::operator==(const vec3& v) const
{
    return x == v.x && y == v.y && z == v.z;
}

bool vec3::operator!=(const vec3& v) const
{
    return !(*this == v);
}

vec3 operator*(float s, const vec3& v)
{
    return v * s;
}