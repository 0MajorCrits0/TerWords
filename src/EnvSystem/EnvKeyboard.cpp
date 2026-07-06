#include "EnvSystem/EnvKeyboard.h"

#include "InputMessage.h"

void EnvKeyboard::update(InputMessage* input)
{
    for (int i = 0; i < 512; i++)
        input->prev[i] = input->curr[i];
}

