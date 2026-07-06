#include "InputMessage.h"

bool InputMessage::isKeyPressedOnce(int key) const
{
    if (key < 0 || key >= 512) return false;
    return curr[key] && !prev[key];
}

bool InputMessage::isKeyDown(int key) const
{
    if (key < 0 || key >= 512) return false;
    return curr[key];
}

bool InputMessage::isKeyReleased(int key) const
{
    if (key < 0 || key >= 512) return false;
    return !curr[key] && prev[key];
}
