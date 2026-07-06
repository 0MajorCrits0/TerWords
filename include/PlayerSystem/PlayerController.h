#pragma once

#include "MathObjects.h"

class InputMessage;
class PlayerMessage;

class PlayerController
{
public:
    PlayerController();
    
    void update(PlayerMessage* player, InputMessage* input, float deltaTime);
};