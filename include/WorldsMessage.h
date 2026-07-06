#pragma once

#include "MathObjects.h"

#include <vector>
#include <unordered_map>

struct World;
struct PositionedChunk;

class PlayerMessage;

class WorldsMessage
{
public:
    std::vector<World*> worlds;
    std::unordered_map<World*, std::vector<PositionedChunk*>> chunks;
};