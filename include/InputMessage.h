#pragma once

struct InputMessage
{
public:
    bool isKeyPressedOnce(int key) const;
    bool isKeyDown(int key) const;
    bool isKeyReleased(int key) const;
    
    friend class EnvManager;
    friend class EnvKeyboard;
private:
    bool prev[512] = {};
    bool curr[512] = {};
};