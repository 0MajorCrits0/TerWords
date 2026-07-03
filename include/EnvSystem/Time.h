#pragma once

class Time {
public:
    void update();
    float getDeltaTime();

private:
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
};