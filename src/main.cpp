#include <iostream>
#include "Window.h"
#include "KeyboardHandler.h"
#include "WindowHandlerProxy.h"

#include "RenderSystem/Aggregation.h"
#include "RenderSystem/Program.h"

float vertices[] =
{
    // Прямоугольник 1 (центр)
    -0.3f, -0.15f,
    -0.3f,  0.15f,
     0.3f, -0.15f,
     0.3f,  0.15f,

    // Прямоугольник 2 (слева сверху, меньше)
    -0.9f,  0.8f,
    -0.9f,  0.6f,
    -0.6f,  0.8f,
    -0.6f,  0.6f,
};

float vertices1[] =
{
    // Прямоугольник 3 (справа снизу, вытянутый)
     0.4f, -0.4f,
     0.4f, -0.1f,
     0.9f, -0.4f,
     0.9f, -0.1f,

    // Прямоугольник 4 (маленький, ближе к центру)
    -0.1f,  0.4f,
    -0.1f,  0.2f,
     0.1f,  0.4f,
     0.1f,  0.2f,

    // Прямоугольник 5 (диагонально смещённый)
    -0.8f, -0.6f,
    -0.6f, -0.4f,
    -0.4f, -0.8f,
    -0.2f, -0.6f
};

int main(int argc, const char** argv)
{
	Window window;
	KeyboardHandler keyboard;
	WindowHandlerProxy proxy;
	proxy.init(&window, &keyboard);

	Program program("vert.glsl", "frag.glsl");
	Aggregation agg(true);
	agg.add(vertices, sizeof(vertices) / sizeof(float));
	agg.add(vertices1, sizeof(vertices1) / sizeof(float));
    
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