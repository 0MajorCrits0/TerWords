#pragma once

#include <vector>

struct WorldsMessage;
struct PlayerMessage;

class WorldInstance;
class WorldDatabase;
class WorldGenerator;
class WorldChunkSelector;

class WorldManager
{
public:
    void init(WorldsMessage* data);
    void update(PlayerMessage* player, WorldsMessage* scene);
    void deinit();

    void switchDebugging();
private:
    std::vector<WorldInstance*> worldInstances;
    WorldChunkSelector* selector;
    WorldGenerator* generator;
    WorldDatabase* db;
    bool debug;
};