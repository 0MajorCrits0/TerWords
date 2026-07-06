#pragma once

#include "MathObjects.h"

#include <vector>

class RenderGroup;
class RenderWorld;
class PlayerMessage;
class WorldsMessage;
class RenderProgram;

class RenderManager
{
public:
    void init();
    void update(WorldsMessage* data, PlayerMessage* player, mat4 ortho);
    void deinit();

private:
    RenderProgram* program;
    RenderWorld* renderer;
    RenderGroup* scene;
};