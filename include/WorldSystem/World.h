#pragma once

#include <cstddef>
#include "Config.h"
#include "MathObjects.h"
#include <vector>

struct Block
{
    char id = 1;
};

struct Chunk
{
    Block blocks[CHUNKSIZE][CHUNKSIZE];
};

class World
{
public:
    World(std::size_t width, std::size_t height);
    ~World();


    Chunk* getChunk(int x, int y);
    void setChunk(std::size_t x, std::size_t y, Chunk* chunk);

    void setBlock(std::size_t x, std::size_t y, const Block& block);
    Block getBlock(std::size_t x, std::size_t y) const;

    friend class WorldRenderer;
    friend class WorldGenerator;
    friend class WorldLoader;

    std::size_t width;
    std::size_t height;
    Block** blocks;
};

struct WorldInstance
{
    World* world;
    vec2 position;
};