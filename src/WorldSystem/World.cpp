#include "WorldSystem/World.h"
#include <cstring>

World::World(std::size_t width, std::size_t height) : width(width), height(height)
{
    blocks = new Block*[height];

    for (std::size_t y = 0; y < height; ++y)
    {
        blocks[y] = new Block[width];
        std::memset(blocks[y], 0, width * sizeof(Block));
    }
}

World::~World()
{
    for (std::size_t y = 0; y < height; ++y)
        delete[] blocks[y];

    delete[] blocks;
}

Chunk* World::getChunk(int x, int y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return nullptr;
    Chunk* chunk = new Chunk();

    x = x - (x % CHUNKSIZE);
    y = y - (y % CHUNKSIZE);

    bool valid = false;
    for (int i = 0; i < CHUNKSIZE; ++i)
        for (int j = 0; j < CHUNKSIZE; ++j) {
            chunk->blocks[i][j] = getBlock(x + j, y + i);
            if (!valid && chunk->blocks[i][j].id != 0)
                valid = true;
        }

    if (!valid)
    {
        delete chunk;
        return nullptr;
    }

    return chunk;
}

void World::setChunk(std::size_t x, std::size_t y, Chunk* chunk)
{
    if (x % CHUNKSIZE != 0 || y % CHUNKSIZE != 0)
        return;
    
    for (std::size_t j = 0; j < CHUNKSIZE; ++j)
        for (std::size_t i = 0; i < CHUNKSIZE; ++i)
            blocks[y + j][x + i] = chunk->blocks[j][i];
        
}

void World::setBlock(std::size_t x, std::size_t y, const Block& block)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return;
    blocks[y][x] = block;
}

Block World::getBlock(std::size_t x, std::size_t y) const
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return Block(0);

    return blocks[y][x];
}