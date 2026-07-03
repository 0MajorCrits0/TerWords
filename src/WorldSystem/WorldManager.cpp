#include "WorldSystem/WorldManager.h"
#include "Config.h"
#include "MathObjects.h"
#include "WorldSystem/World.h"
#include "WorldSystem/WorldGenerator.h"
#include "WorldSystem/WorldGenerator.h"
#include "WorldSystem/WorldChunkLoader.h"
#include "WorldFrameData.h"

void WorldManager::init()
{
    loader = new WorldChunkLoader();
    generator = new WorldGenerator();

    World* world = new World(32, 16);
    WorldInstance* inst = new WorldInstance();
    inst->position = vec2(7, -16);
    inst->world = world;
    worldInstances.push_back(inst);

    World* world2 = new World(16, 8);
    WorldInstance* inst2 = new WorldInstance();
    inst2->position = vec2(3, 10);
    inst2->world = world2;
    worldInstances.push_back(inst2);

    WorldGenerator generator;
    generator.generate(world);
    generator.generate(world2);
}

void WorldManager::update(vec2 cameraPosition, WorldFrameData* data)
{
    for (WorldInstance* inst : worldInstances)
    {
        ActiveArea* visible = loader->getChunks(inst, cameraPosition);
        data->areas.push_back(visible);
    }
}

void WorldManager::deinit()
{
    for (WorldInstance* instance : worldInstances)
    {
        World* world = instance->world;
        delete world;
        delete instance;
    }
    worldInstances.clear();

    delete loader;
    delete generator;
}