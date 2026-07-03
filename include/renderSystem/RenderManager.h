#pragma once

#include <vector>
#include "MathObjects.h"

class Program;
class SceneGroup;
class WorldRenderer;
class WorldFrameData;

class RenderManager
{
public:
    void init();
    void update(WorldFrameData* data, mat4 ortho);
    void deinit();

private:
    Program* program;
    WorldRenderer* renderer;
    SceneGroup* scene;
};