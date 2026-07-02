#include <iostream>
#include "Window.h"
#include "KeyboardHandler.h"
#include "WindowHandlerProxy.h"

#include "renderSystem/Aggregation.h"
#include "renderSystem/Program.h"

#include "World.h"
#include "renderSystem/WorldRenderer.h"

int main(int argc, const char** argv)
{
	Window window;
	KeyboardHandler keyboard;
	WindowHandlerProxy proxy;
	proxy.init(&window, &keyboard);

	Program program("vert.glsl", "frag.glsl");
	Aggregation agg(true);

    World world1(16, 4, vec2(0));
    World world2(20, 5, vec2(1, 0.3));
    World world3(20, 8, vec2(-1, -0.7));

    WorldRenderer renderer;
    renderer.generate(world1, agg);
    renderer.generate(world2, agg);
    renderer.generate(world3, agg);

    while (!window.windowShouldClose())
    {
        if (keyboard.isKeyDown(GLFW_KEY_ESCAPE))
			window.windowSetShouldClose();
		
		window.clear();
		program.use();
        program.setUniform("orthoMatrix", proxy.getOrthoMatrix());
		agg.render();
		window.update();	
    }
    
    return 0;
}