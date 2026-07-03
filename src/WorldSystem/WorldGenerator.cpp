#include "WorldSystem/WorldGenerator.h"
#include "WorldSystem/World.h"

void WorldGenerator::generate(World* world)
{
    int i = 0;
    for (int x = 0; x < world->width; ++x)
    {
        Block block;
        block.id = i % 2;
        world->setBlock(x, world->height - 1, block);
        i++;
    }

    for (int x = 0; x < world->width; ++x)
        for (int y = 0; y < world->height - 1; ++y)
        {
            Block block;
            block.id = 1;
            world->setBlock(x, y, block);
        }
}