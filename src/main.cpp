#include <iostream>
#include "Window.h"
#include "KeyboardHandler.h"
#include "WindowHandlerProxy.h"

int main(int argc, const char** argv)
{
	Window window;
	KeyboardHandler keyboard;
	WindowHandlerProxy proxy;
	proxy.init(&window, &keyboard);

    while (!window.windowShouldClose())
    {
        if (keyboard.isKeyDown(GLFW_KEY_ESCAPE))
			window.windowSetShouldClose();

		window.update();
    }

    return 0;
}