#include "PhysicsSystem/PhysicsPlayer.h"

#include "PlayerMessage.h"
#include "MathObjects.h"
#include "WorldsMessage.h"
#include "Config.h"
#include "World.h"

void PhysicsPlayer::update(WorldsMessage* broker, PlayerMessage* player, float deltaTime)
{
    if (!physicsEnabled)
        return;
    
    vec2 resultant = vec2(0,0);
    for (World* world : broker->worlds)
    {
        float diff = length(player->position - world->position);
        diff = min(diff, world->height);
        float mass = diff * diff;
        vec2 radiusVector = player->position - world->position;
        float radius = sqrt(radiusVector.x * radiusVector.x + radiusVector.y * radiusVector.y);
        radius = max(radius, 0.01f);
        resultant += -radiusVector * (GRAVITY * mass / pow(radius, 3));
    }

    player->speed += resultant * deltaTime;
}

void PhysicsPlayer::switchPhysicsPlayer()
{
    physicsEnabled = !physicsEnabled;
}