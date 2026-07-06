#include "WorldSystem/WorldChunkSelector.h"

#include "PlayerMessage.h"
#include "MathObjects.h"
#include "Config.h"
#include "World.h"

void WorldChunkSelector::getChunks(World* world, PlayerMessage* player)
{
    static int radius = LOADINGAREA / 2;

    float X = player->position.x - world->position.x;
    float Y = player->position.y - world->position.y;

    X /= CHUNKSIZE;
    Y /= CHUNKSIZE;

    float r = sqrt(X * X + Y* Y);
    float a = atan2(Y, X);

    while (a < 0.0f)
        a += 2.0f * 3.141592f;

    int xn = (a / (2.0f * 3.141592f)) * world->width ;
    int yn = r;

    for (int i = -radius; i <= radius; ++i)
        for (int j = -radius; j <= radius; ++j)
        {
            int xp = xn + j;
            int yp = yn + i;

            if (xp < 0) xp = world->width + xp;
            if (xp > world->width - 1) xp = world->width - xp;

            if (xp >= 0 && xp < world->width && yp >= 0 && yp < world->height)
                world->visibleChunksPos.emplace_back(xp, yp);
        }    
}