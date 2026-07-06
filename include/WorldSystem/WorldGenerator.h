#pragma once

class World;
class WorldDatabase;

class WorldGenerator
{
public:
    void generate(World* world, WorldDatabase* db);
};