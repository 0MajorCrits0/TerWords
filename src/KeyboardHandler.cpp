#include "KeyboardHandler.h"

bool KeyboardHandler::isKeyPressedOnce(int key) const
{
    if (key < 0 || key >= 512) return false;
    return curr[key] && !prev[key];
}

bool KeyboardHandler::isKeyDown(int key) const
{
    if (key < 0 || key >= 512) return false;
    return curr[key];
}

bool KeyboardHandler::isKeyReleased(int key) const
{
    if (key < 0 || key >= 512) return false;
    return !curr[key] && prev[key];
}

void KeyboardHandler::update()
{
    for (int i = 0; i < 512; i++)
        prev[i] = curr[i];
}

