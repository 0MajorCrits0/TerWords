#pragma once

#include <vector>

struct vec2;
struct WorldFrameData;

class WorldInstance;
class WorldGenerator;
class WorldChunkLoader;

class WorldManager
{
public:
    void init();
    void update(vec2 cameraPosition, WorldFrameData* scene);
    void deinit();

private:
    std::vector<WorldInstance*> worldInstances;
    WorldChunkLoader* loader;
    WorldGenerator* generator;
};