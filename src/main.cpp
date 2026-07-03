#include "Config.h"
#include "EnvSystem/Time.h"
#include "PlayerController.h"
#include "EnvSystem/Keyboard.h"
#include "renderSystem/SceneGroup.h"
#include "WorldSystem/WorldManager.h"
#include "RenderSystem/RenderManager.h"
#include "EnvSystem/EnvironmentManager.h"
#include "WorldFrameData.h"

int main(int argc, const char** argv)
{
    Keyboard* keyboard = new Keyboard();
    
	EnvironmentManager envManager;
    envManager.init(keyboard);

    WorldManager wldManager;
    wldManager.init();

    PlayerController player(STARTPOS, 10.0f);

    RenderManager rndManager;
    rndManager.init();

    Time time;   
    while (envManager.isWorking())
    {
        time.update();
        player.update(keyboard, time.getDeltaTime());
		envManager.update();

        WorldFrameData data;
        wldManager.update(player.getPosition(), &data);
        rndManager.update(&data, envManager.getOrthoMatrix());
    }

    envManager.deinit();
    wldManager.deinit();
    rndManager.deinit();

    delete keyboard;

    return 0;
}