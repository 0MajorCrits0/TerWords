#include "RenderSystem/RenderManager.h"
#include "RenderSystem/RenderWorld.h"
#include "RenderSystem/Rendergroup.h"
#include "RenderSystem/RenderProgram.h"

#include "PlayerMessage.h"
#include "WorldsMessage.h"
#include "World.h"

void RenderManager::init()
{
    program = new RenderProgram("vert.glsl", "frag.glsl");
    renderer = new RenderWorld();
    scene = new RenderGroup(true);
}

void RenderManager::update(WorldsMessage* data, PlayerMessage* player, mat4 ortho)
{  

    glClearColor(0.1f, 0.2f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program->use();
    program->setUniform("orthoMatrix", ortho);
    
    scene->clear();
    for (World* world : data->worlds) {
        renderer->generate(data, player, scene);
    }
    scene->render();
    
}

void RenderManager::deinit()
{
    delete program;
    delete renderer;
    delete scene;
}