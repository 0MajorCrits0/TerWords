#pragma once

class WindowHandlerProxy;

class KeyboardHandler
{
public:
    bool isKeyPressedOnce(int key) const;
    bool isKeyDown(int key) const;
    bool isKeyReleased(int key) const;
    void update();

    friend class WindowHandlerProxy;
private:
    bool prev[512] = {};
    bool curr[512] = {};
};