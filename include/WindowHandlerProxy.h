#pragma once

#include <memory>

class Window;
class KeyboardHandler;

class WindowHandlerProxy
{
public:
    void init(const Window* window, const KeyboardHandler* keyboard);
};