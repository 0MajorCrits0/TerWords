#pragma once

class WindowHandlerProxy;

class Keyboard
{
public:
    bool isKeyPressedOnce(int key) const;
    bool isKeyDown(int key) const;
    bool isKeyReleased(int key) const;
    void update();

    friend class EnvironmentManager;
private:
    bool prev[512] = {};
    bool curr[512] = {};
};