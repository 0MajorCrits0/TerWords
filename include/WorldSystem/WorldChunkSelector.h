#pragma once

#include "MathObjects.h"

#include <vector>

struct World;

class PlayerMessage;

class World;

class WorldChunkSelector
{
public:
    void getChunks(World* world, PlayerMessage* player);
};