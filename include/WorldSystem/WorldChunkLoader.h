#pragma once

#include <vector>
#include "MathObjects.h"
#include "World.h"

class World;
class Chunk;

struct ActiveArea
{
    WorldInstance* instance;
    std::vector<vec2> visibleChunks;
};

class WorldChunkLoader
{
public:
    ActiveArea* getChunks(WorldInstance* instance, vec2 position);
};