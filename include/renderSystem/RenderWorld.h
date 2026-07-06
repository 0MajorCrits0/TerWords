#pragma once

#include <vector>

struct PlayerMessage;
struct WorldsMessage;

class RenderGroup;

class RenderWorld
{
public:
    void generate(WorldsMessage* data, PlayerMessage* player, RenderGroup* scene);
};  