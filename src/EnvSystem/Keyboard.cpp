#include "EnvSystem/Keyboard.h"

bool Keyboard::isKeyPressedOnce(int key) const
{
    if (key < 0 || key >= 512) return false;
    return curr[key] && !prev[key];
}

bool Keyboard::isKeyDown(int key) const
{
    if (key < 0 || key >= 512) return false;
    return curr[key];
}

bool Keyboard::isKeyReleased(int key) const
{
    if (key < 0 || key >= 512) return false;
    return !curr[key] && prev[key];
}

void Keyboard::update()
{
    for (int i = 0; i < 512; i++)
        prev[i] = curr[i];
}

