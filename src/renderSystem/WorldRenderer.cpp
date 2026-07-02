#include "renderSystem/WorldRenderer.h"
#include "renderSystem/Aggregation.h"
#include "World.h"

void WorldRenderer::generate(const World& world, Aggregation& aggregation)
{
    for (int x = 0; x < world.width; ++x)
        for (int y = 0; y < world.height; ++y)
        {
            Block block = world.getBlock(x, y);
            if (block.id != 1)
            {
                float x0 = x * BLOCKSIZE;
                float y0 = y * BLOCKSIZE;
                
                std::vector<float> vertices =
                {
                    x0, y0,
                    x0, y0 + BLOCKSIZE,
                    x0 + BLOCKSIZE, y0,
                    x0 + BLOCKSIZE, y0 + BLOCKSIZE
                };
                
                for (int i = 0; i < 8; i += 2)
                {
                    float angle = 2.0f * 3.141592f * vertices[i] / (world.width * BLOCKSIZE);
                    float radius = vertices[i + 1];
                    vertices[i] = radius * cos(angle) + world.position.x;
                    vertices[i + 1] = radius * sin(angle) + world.position.y;   
                }

                aggregation.add(vertices.data(), vertices.size());
            }
        }
}