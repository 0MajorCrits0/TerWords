#include "PlayerSystem/PlayerController.h"


#include "PlayerMessage.h"
#include "MathObjects.h"
#include "InputMessage.h"
#include "glad/glad.h"

#include <GLFW/glfw3.h>

PlayerController::PlayerController()
{
}

void PlayerController::update(PlayerMessage* player, InputMessage* input, float deltaTime)
{
    vec2 direction(0.0f, 0.0f);

    if (input->isKeyDown(GLFW_KEY_W))
        direction.y += 1.0f;

    if (input->isKeyDown(GLFW_KEY_S))
        direction.y -= 1.0f;

    if (input->isKeyDown(GLFW_KEY_A))
        direction.x -= 1.0f;

    if (input->isKeyDown(GLFW_KEY_D))
        direction.x += 1.0f;

    if (direction.x != 0.0f || direction.y != 0.0f)
    {
        direction = normalize(direction) * player->buster;
        player->speed += (direction * deltaTime);
    }

    if (input->isKeyDown(GLFW_KEY_E))
    {
        player->scale += deltaTime;
        player->scale = min(player->scale, 4.0f);
    }

    if (input->isKeyDown(GLFW_KEY_Q))
    {
        player->scale -= deltaTime;
        player->scale = max(player->scale, 0.25f);
    }
}