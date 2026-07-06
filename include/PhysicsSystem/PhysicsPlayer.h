#pragma once

#include <vector>

struct WorldsMessage;
struct PlayerMessage;

class PhysicsPlayer
{
public:
    void update(WorldsMessage* broker, PlayerMessage* player, float deltaTime);
    void switchPhysicsPlayer();

private:
    bool physicsEnabled = true;
};