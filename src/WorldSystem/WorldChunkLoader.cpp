#include "WorldSystem/WorldChunkLoader.h"
#include "WorldSystem/World.h"
#include "MathObjects.h"
#include "Config.h"

ActiveArea* WorldChunkLoader::getChunks(WorldInstance* instance, vec2 position)
{
    static int radius = LOADINGAREA / 2;

    ActiveArea* area = new ActiveArea();
    area->instance = instance;

    float X = position.x - instance->position.x;
    float Y = position.y - instance->position.y;

    float r = sqrt(X * X + Y* Y);
    float a = atan2(Y, X);

    while (a < 0.0f)
        a += 2.0f * 3.141592f;

    int xn = (a / (2.0f * 3.141592f)) * instance->world->width;
    int yn = r;

    xn = xn - (xn % CHUNKSIZE);
    yn = yn - (yn % CHUNKSIZE);
    
    for (int i = -radius; i <= radius; ++i)
        for (int j = -radius; j <= radius; ++j)
        {
            int xp = xn + j * CHUNKSIZE;
            int yp = yn + i * CHUNKSIZE;

            if (xp < 0) xp = instance->world->width + xp;
             
            bool flag = false;
            int kk = 0;
           
            while (yp < 0)
            {
                flag = true;
                
                for (int p = 0; p < instance->world->width; p += CHUNKSIZE) 
                    if (p >= 0 && p < instance->world->width && kk >= 0 && kk < instance->world->height)
                        area->visibleChunks.emplace_back(p, kk);
                
                kk += CHUNKSIZE;
                yp += CHUNKSIZE;
                
            }
            if (flag)
            {
                i = -1;
                break;
            }
                
            if (xp >= 0 && xp < instance->world->width && yp >= 0 && yp < instance->world->height)
                area->visibleChunks.emplace_back(xp, yp);
        }    
    
    return area;
}