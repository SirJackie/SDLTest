#ifndef __CSBF_KeyboardSupport__
#define __CSBF_KeyboardSupport__

#include "BasicDataTypeDeclarations.h"


class CS_Keyboard {
private:
	csbool keyBuffer[256];
public:
	CS_Keyboard();
	csbool IsKeyPressed(i8 key);
	void   SimuLayerSetKeyIsPressed(i8 key);
	void   SimuLayerSetKeyIsReleased(i8 key);
};


#endif
