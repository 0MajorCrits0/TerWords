#pragma once

#include "World.h"
#include "MathObjects.h"

#include <vector>
#include <string>

struct World;
struct PositionedChunk;

class WorldDatabase
{
public:
    WorldDatabase(std::string saveDirectory);

    std::vector<World*> readWorlds();

    std::vector<PositionedChunk*> readChunks(World* world);

    std::vector<PositionedChunk*> readAllChunks(World* world);

    void writeChunks(World* world, std::vector<PositionedChunk*> chunks);

    void createWorld(World* world);

    void deleteWorld(uint64_t worldId);

private:
    std::string saveDirectory;
};