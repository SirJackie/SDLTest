#include "KeyboardSupport.h"

CS_Keyboard::CS_Keyboard()
{
    for (i32 i = 0; i < 256; i++) {
        keyBuffer[i] = csFalse;
    }
}

csbool CS_Keyboard::IsKeyPressed(i8 key)
{
    return keyBuffer[key];
}

void CS_Keyboard::SimuLayerSetKeyIsPressed(i8 key)
{
    keyBuffer[key] = csTrue;
}

void CS_Keyboard::SimuLayerSetKeyIsReleased(i8 key)
{
    keyBuffer[key] = csFalse;
}
