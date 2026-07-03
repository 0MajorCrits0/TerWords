#include "RenderSystem/WorldRenderer.h"
#include "WorldSystem/WorldChunkLoader.h"
#include "RenderSystem/SceneGroup.h"
#include "WorldSystem/World.h"

void renderChunk(SceneGroup* scene, WorldInstance* instance, vec2 position)
{
    World* world = instance->world;
    vec2 globalPosition = instance->position;
    for (int x0 = 0; x0 < CHUNKSIZE; x0++)
        for (int y0 = 0; y0 < CHUNKSIZE; y0++)
        {
            float x = position.x + x0;
            float y = position.y + y0;

            Block block = world->getBlock(x, y);
            if (block.id != 0)
            {
                
                std::vector<float> vertices =
                {
                    x, y,
                    x, y + 1,
                    x + 1, y,
                    x + 1, y + 1
                };
                
                for (int i = 0; i < 8; i += 2)
                {
                    float angle = 2.0f * 3.141592f * vertices[i] / world->width;
                    float radius = vertices[i + 1];

                    vertices[i]     = (radius * cos(angle) + globalPosition.x) * BLOCKSIZE;
                    vertices[i + 1] = (radius * sin(angle) + globalPosition.y) * BLOCKSIZE;
                }
                
                for (int i = 0; i < 8; i += 2)
                {
                    //vertices[i] = (vertices[i] + world.position.x) * BLOCKSIZE;
                    //vertices[i + 1] = (vertices[i + 1] + world.position.y) * BLOCKSIZE;
                }
                scene->add(vertices.data(), vertices.size());
            }
        }
}

void WorldRenderer::generate(ActiveArea* area, SceneGroup* scene)
{
    for (vec2 chunkPos : area->visibleChunks)
        renderChunk(scene, area->instance, chunkPos);
}


void WorldRenderer::generate(const World& world, SceneGroup* scene)
{
    for (float x = 0; x < world.width; ++x)
        for (float y = 0; y < world.height; ++y)
        {
            Block block = world.getBlock(x, y);
            if (block.id != 0)
            {
                
                std::vector<float> vertices =
                {
                    x, y,
                    x, y + 1,
                    x + 1, y,
                    x + 1, y + 1
                };
                
                for (int i = 0; i < 8; i += 2)
                {
                    float angle = 2.0f * 3.141592f * vertices[i] / world.width;
                    float radius = vertices[i + 1];

                    //vertices[i] = (radius * cos(angle) + world.position.x) * BLOCKSIZE;
                    //vertices[i + 1] = (radius * sin(angle) + world.position.y) * BLOCKSIZE;
                }
                
                for (int i = 0; i < 8; i += 2)
                {
                    //vertices[i] = (vertices[i] + world.position.x) * BLOCKSIZE;
                    //vertices[i + 1] = (vertices[i + 1] + world.position.y) * BLOCKSIZE;
                }
                scene->add(vertices.data(), vertices.size());
            }
        }
}