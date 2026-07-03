#pragma once

#include <memory>
#include "MathObjects.h"

struct Pocket;

class Window;
class Keyboard;

class EnvironmentManager
{
public:
    void init(Keyboard* keyboard);
    void update();
    void deinit();

    mat4 getOrthoMatrix();
    bool isWorking();
private:
    Pocket* pocket;
};

struct Pocket
{
    Window* window;
    Keyboard* keyboard;
    mat4 orthoMatrix;
};
