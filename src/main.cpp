#include "EnvSystem/EnvTime.h"
#include "EnvSystem/EnvManager.h"

#include "PhysicsSystem/PhysicsPlayer.h"

#include "RenderSystem/RenderManager.h"

#include "PlayerSystem/PlayerController.h"

#include "WorldSystem/WorldManager.h"

#include "PlayerMessage.h"
#include "InputMessage.h"
#include "WorldsMessage.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Config.h"
#include "World.h"

int main(int argc, const char** argv)
{
    PlayerMessage player;
    player.position = vec2(0, 0);
    player.scale = 1.0f;
    player.speed = vec2(0, 0);
    player.angleRotate = 0.0f;
    player.buster = 12.0f;

    WorldsMessage worldsMessage;

    InputMessage inputMessage;
    
    //-----------------------

    WorldManager wldManager;
    wldManager.init(&worldsMessage);
    //wldManager.switchDebugging();

    EnvManager envManager;
    envManager.init(&inputMessage);

    RenderManager rndManager;
    rndManager.init();

    //----------------------

    PlayerController playerController;

    PhysicsPlayer playerPhysics;

    //----------------------
    bool debug = true;
    EnvTime time;   
    while (envManager.isWorking())
    {
        time.update();
        envManager.update();
        playerController.update(&player, &inputMessage, time.getDeltaTime());

        wldManager.switchDebugging();
        if (debug)
        {
            wldManager.update(&player, &worldsMessage);
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            rndManager.update(&worldsMessage, &player, envManager.getOrthoMatrix());
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

        wldManager.switchDebugging();
        if (!debug)
        {
            wldManager.update(&player, &worldsMessage);
            rndManager.update(&worldsMessage, &player, envManager.getOrthoMatrix());
    
        }
        playerPhysics.update(&worldsMessage, &player, time.getDeltaTime());
        player.position += player.speed * time.getDeltaTime();

        if (inputMessage.isKeyPressedOnce(GLFW_KEY_R))
            debug = !debug;
    }

    //-------------------------

    for (auto world : worldsMessage.worlds) {
        for (auto chunk : worldsMessage.chunks[world])
                        delete chunk;
        worldsMessage.chunks[world].clear();
        delete world;
    }
    worldsMessage.worlds.clear();

    //-------------------------

    envManager.deinit();
    wldManager.deinit();
    rndManager.deinit();

    return 0;
}