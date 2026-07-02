#pragma once

#include <memory>
#include "MathObjects.h"

class Window;
class KeyboardHandler;

class WindowHandlerProxy
{
public:
    void init(Window* window, KeyboardHandler* keyboard);
    void update();
    mat4 getOrthoMatrix();
private:
    mat4 orthoMatrix;
};