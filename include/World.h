#pragma once

#include "MathObjects.h"
#include "Config.h"

#include <vector>

#pragma pack(push, 1)
struct Block
{
    char id = 1;
};

struct Chunk
{
    char blocks[CHUNKSIZE][CHUNKSIZE] = {};
    
    
};

inline bool operator==(const Chunk& a, const Chunk& b)
{
    for (int y = 0; y < CHUNKSIZE; ++y)
        for (int x = 0; x < CHUNKSIZE; ++x)
            if (a.blocks[y][x] != b.blocks[y][x])
                return false;

    return true;
}
struct PositionedChunk
{
    Chunk* chunk;
    vec2 position;
};
#pragma pack(pop)

struct World
{
    int id;
    int width, height;
    vec2 position;
    vec2 velocity;
    std::vector<vec2> visibleChunksPos;
};