#include "World.h"

#include <cstring>

World::World(std::size_t width, std::size_t height, vec2 position) : width(width), height(height), position(position)
{
    chunks = new Block*[height];

    for (std::size_t y = 0; y < height; ++y)
    {
        chunks[y] = new Block[width];
        std::memset(chunks[y], 0, width * sizeof(Block));
    }
}

World::~World()
{
    for (std::size_t y = 0; y < height; ++y)
        delete[] chunks[y];

    delete[] chunks;
}

Chunk* World::getChunk(std::size_t x, std::size_t y)
{
    if (x % CHUNKSIZE != 0 || y % CHUNKSIZE != 0)
        return nullptr;

    Chunk* chunk = new Chunk();
    for (int i = 0; i < CHUNKSIZE; ++i)
        for (int j = 0; j < CHUNKSIZE; ++j)
            chunk->blocks[i][j] = chunks[y + i][x + j];

    return chunk;
}

void World::setChunk(std::size_t x, std::size_t y, Chunk* chunk)
{
    if (x % CHUNKSIZE != 0 || y % CHUNKSIZE != 0)
        return;
    
    for (std::size_t j = 0; j < CHUNKSIZE; ++j)
        for (std::size_t i = 0; i < CHUNKSIZE; ++i)
        {
            chunks[y + j][x + i] = chunk->blocks[j][i];
        }
    
}

void World::setBlock(std::size_t x, std::size_t y, const Block& block)
{
    chunks[y][x] = block;
}

Block World::getBlock(std::size_t x, std::size_t y) const
{
    return chunks[y][x];
}