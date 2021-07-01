#ifndef __CSBF_Main__
#define __CSBF_Main__

#include "./CrossBufferLayer/CrossBuffer.h"


/* Define Window Class Properties */
#define WindowClassName    L"CrossBuffer Class"
#define WindowTitle        L"CrossBuffer <Press WASD and IJKL to move the position>"

void Setup  (CS_FrameBuffer& fb, CS_Keyboard kb, i32 deltaTime);
void Update (CS_FrameBuffer& fb, CS_Keyboard kb, i32 deltaTime);

#endif
