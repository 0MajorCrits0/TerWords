#include "PlayerController.h"
#include "EnvSystem/Keyboard.h"
#include "MathObjects.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>

PlayerController::PlayerController(vec2 position, float speed)
{
    this->position = position;
    this->speed = speed;
}

void PlayerController::update(Keyboard* keyboard, float deltaTime)
{
    vec2 direction(0.0f,0.0f);

    if (keyboard->isKeyDown(GLFW_KEY_W))
        direction.y += 1.0f;

    if (keyboard->isKeyDown(GLFW_KEY_S))
        direction.y -= 1.0f;

    if (keyboard->isKeyDown(GLFW_KEY_A))
        direction.x -= 1.0f;

    if (keyboard->isKeyDown(GLFW_KEY_D))
        direction.x += 1.0f;

    if (direction.x != 0.0f || direction.y != 0.0f)
    {
        direction = normalize(direction);
        position += direction * speed * deltaTime;
    }
}

vec2 PlayerController::getPosition()
{
    return position;
}