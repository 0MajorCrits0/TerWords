#include "RenderSystem/RenderManager.h"
#include "RenderSystem/SceneGroup.h"
#include "RenderSystem/Program.h"
#include "MathObjects.h"
#include "RenderSystem/WorldRenderer.h"
#include "WorldFrameData.h"

void RenderManager::init()
{
    program = new Program("vert.glsl", "frag.glsl");
    renderer = new WorldRenderer();
    scene = new SceneGroup(true);
}

void RenderManager::update(WorldFrameData* data, mat4 ortho)
{  

    glClearColor(0.1f, 0.2f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program->use();
    program->setUniform("orthoMatrix", ortho);
    
    for (ActiveArea* area : data->areas)
        renderer->generate(area, scene);
    
    scene->render();
    scene->clear();
}

void RenderManager::deinit()
{
    delete program;
    delete renderer;
    delete scene;
}