#pragma once

#include <vector>

struct ActiveArea;

class World;
class SceneGroup;

class WorldRenderer
{
public:
    void generate(ActiveArea* area, SceneGroup* scene);
    void generate(const World& world, SceneGroup* scene);
};  