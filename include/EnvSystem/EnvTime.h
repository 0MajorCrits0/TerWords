#pragma once

class EnvTime {
public:
    void update();
    float getDeltaTime();

private:
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
};