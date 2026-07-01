#include <iostream>
#include "Window.h"
#include "KeyboardHandler.h"
#include "WindowHandlerProxy.h"

#include "RenderSystem/Aggregation.h"
#include "RenderSystem/Program.h"

float vertices[] =
{
    -0.8f,  0.8f,
    -0.4f,  0.8f,
    -0.4f,  0.4f,

    -0.8f,  0.8f,
    -0.4f,  0.4f,
    -0.8f,  0.4f,


     0.2f,  0.7f,
     0.7f,  0.7f,
     0.7f,  0.5f,

     0.2f,  0.7f,
     0.7f,  0.5f,
     0.2f,  0.5f,


    -0.2f,  0.1f,
     0.4f,  0.1f,
     0.4f, -0.3f,

    -0.2f,  0.1f,
     0.4f, -0.3f,
    -0.2f, -0.3f,


    -0.9f, -0.5f,
    -0.6f, -0.5f,
    -0.6f, -0.9f,

    -0.9f, -0.5f,
    -0.6f, -0.9f,
    -0.9f, -0.9f,


     0.5f, -0.2f,
     0.9f, -0.2f,
     0.9f, -0.8f,

     0.5f, -0.2f,
     0.9f, -0.8f,
     0.5f, -0.8f
};

int main(int argc, const char** argv)
{
	Window window;
	KeyboardHandler keyboard;
	WindowHandlerProxy proxy;
	proxy.init(&window, &keyboard);

	Program program("vert.glsl", "frag.glsl");
	Aggregation agg;
	agg.add(vertices, sizeof(vertices) / sizeof(float));

    while (!window.windowShouldClose())
    {
        if (keyboard.isKeyDown(GLFW_KEY_ESCAPE))
			window.windowSetShouldClose();
		
		window.clear();
		program.use();
		agg.render();
		window.update();	
    }

    return 0;
}