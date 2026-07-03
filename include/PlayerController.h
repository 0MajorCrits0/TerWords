#pragma once

#include "MathObjects.h"

class Keyboard;

class PlayerController
{
public:
    PlayerController(vec2 position, float speed);
    void update(Keyboard* keyboard, float deltaTime);
    vec2 getPosition();

private:
    vec2 position;
    float speed;
};