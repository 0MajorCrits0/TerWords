#pragma once

#include "MathObjects.h"

class PlayerMessage
{
public:
    vec2 position;
    vec2 speed;
    float angleRotate;
    float scale;
    float buster;

    friend class WorldManager;
private:
    vec2 oldPosition = vec2(INT_MAX, INT_MAX);
};