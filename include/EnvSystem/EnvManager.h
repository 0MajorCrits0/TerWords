#pragma once

#include "MathObjects.h"

#include <memory>

struct Pocket;

class EnvWindow;
class EnvKeyboard;
class InputMessage;

class EnvManager
{
public:
    void init(InputMessage* input);
    void update();
    void deinit();

    mat4 getOrthoMatrix();
    bool isWorking();
private:
    Pocket* pocket;
    EnvKeyboard* keyboard;
};

struct Pocket
{
    EnvWindow* window;
    InputMessage* input;
    mat4 orthoMatrix;
};
