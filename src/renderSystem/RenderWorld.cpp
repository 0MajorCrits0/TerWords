#include "RenderSystem/RenderWorld.h"
#include "RenderSystem/RenderGroup.h"

#include "World.h"
#include "WorldsMessage.h"
#include "PlayerMessage.h"

void RenderWorld::generate(WorldsMessage* data, PlayerMessage* player, RenderGroup* scene)
{

    for (auto [world, list] : data->chunks)  
        for (PositionedChunk* posChunk : list)
            for (float x = 0; x < CHUNKSIZE; ++x)
                for (float y = 0; y < CHUNKSIZE; ++y)
                    { 
                        char block = posChunk->chunk->blocks[(int)y][(int)x];
                        if (block != 0)
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
                                vertices[i]     += posChunk->position.x * CHUNKSIZE;
                                vertices[i + 1] += posChunk->position.y * CHUNKSIZE; 
                            }

                            for (int i = 0; i < 8; i += 2)
                            {
                                float angle = 2.0f * 3.141592f * vertices[i] / (world->width * CHUNKSIZE);
                                float radius = vertices[i + 1];

                                vertices[i]     = (radius * cos(angle) + world->position.x - player->position.x) * BLOCKSIZE;
                                vertices[i + 1] = (radius * sin(angle) + world->position.y - player->position.y) * BLOCKSIZE;
                            }
                                
                            scene->add(vertices.data(), vertices.size());
                        }
                    }

        
}