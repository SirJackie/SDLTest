#include "Main.h"

i32 deltaColor = 0;
i32 startX = 100, startY = 100, endX = 200, endY = 200;
f32 step = 0.2f;

void Setup(CS_FrameBuffer& fb, CS_Keyboard kb, i32 deltaTime) {
	;
}

void Update(CS_FrameBuffer& fb, CS_Keyboard kb, i32 deltaTime) {

	startX = CS_iclamp(0, startX, fb.width);
	startY = CS_iclamp(0, startY, fb.height);

	endX = CS_iclamp(0, endX, fb.width);
	endY = CS_iclamp(0, endY, fb.height);

	if (deltaColor == 255) {
		deltaColor = 0;
	}

	for (i32 y = startY; y < endY; y++) {
		for (i32 x = startX; x < endX; x++) {
			fb.redBuffer[y * fb.width + x] = 255 - deltaColor;
			fb.greenBuffer[y * fb.width + x] = deltaColor;
			fb.blueBuffer[y * fb.width + x] = deltaColor;
		}
	}

	if (kb.IsKeyPressed('W')) {
		startY -= deltaTime * step;
	}

	if (kb.IsKeyPressed('S')) {
		startY += deltaTime * step;
	}

	if (kb.IsKeyPressed('A')) {
		startX -= deltaTime * step;
	}

	if (kb.IsKeyPressed('D')) {
		startX += deltaTime * step;
	}

	if (kb.IsKeyPressed('I')) {
		endY -= deltaTime * step;
	}

	if (kb.IsKeyPressed('K')) {
		endY += deltaTime * step;
	}

	if (kb.IsKeyPressed('J')) {
		endX -= deltaTime * step;
	}

	if (kb.IsKeyPressed('L')) {
		endX += deltaTime * step;
	}

	deltaColor += 1;
}
