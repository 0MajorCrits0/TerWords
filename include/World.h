#pragma once

#include <cstddef>
#include "Config.h"
#include "MathObjects.h"

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
    World(std::size_t width, std::size_t height, vec2 position);
    ~World();

    Chunk* getChunk(std::size_t x, std::size_t y);
    void setChunk(std::size_t x, std::size_t y, Chunk* chunk);

    void setBlock(std::size_t x, std::size_t y, const Block& block);
    Block getBlock(std::size_t x, std::size_t y) const;

    friend class WorldRenderer;
private:
    std::size_t width;
    std::size_t height;
    vec2 position;

    Block** chunks;
};