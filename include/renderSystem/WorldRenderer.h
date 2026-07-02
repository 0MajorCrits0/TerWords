#pragma once

class World;
class Aggregation;

class WorldRenderer
{
public:
    void generate(const World& world, Aggregation& aggregation);
};