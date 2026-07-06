#include "WorldSystem/WorldGenerator.h"
#include "WorldSystem/WorldDatabase.h"

#include "Config.h"
#include "World.h"

void generateChunk(Chunk* chunk)
{
    for (int i = 0; i < CHUNKSIZE; i++)
         for (int j = 0; j < CHUNKSIZE; j++)
            chunk->blocks[i][j] = (abs(rand()) % 15);
}

void WorldGenerator::generate(World* world, WorldDatabase* db)
{
    std::vector<PositionedChunk*> posChunks;

    for (int x = 0; x < world->width; x++)
        for (int y = 0; y < world->height; y++)
        {
            vec2 pos = vec2(x, y);
            Chunk* chunk = new Chunk();
            generateChunk(chunk);
            posChunks.push_back(new PositionedChunk(chunk, pos));
        }
        
    db->writeChunks(world, posChunks);

    for (PositionedChunk* posChunk : posChunks)
    {
        delete posChunk->chunk;
        delete posChunk;
    }
    posChunks.clear();
    
            
}