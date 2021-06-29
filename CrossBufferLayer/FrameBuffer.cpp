#include "FrameBuffer.h"
#include <vector>
using std::vector;


void CS_FrameBuffer::AllocateBuffer(i32 width, i32 height)
{
    redBuffer   = new i8[width * height];
    greenBuffer = new i8[width * height];
    blueBuffer  = new i8[width * height];
}

void CS_FrameBuffer::DisAllocateBuffer()
{
    delete[] redBuffer;
    delete[] greenBuffer;
    delete[] blueBuffer;
}

void CS_FrameBuffer::ClearSelfBuffer()
{
    CS_Memset(redBuffer, 0, width * height);
    CS_Memset(greenBuffer, 0, width * height);
    CS_Memset(blueBuffer, 0, width * height);
}

void CS_FrameBuffer::CopySameSizeBuffer(const CS_FrameBuffer& from, CS_FrameBuffer& to)
{
    if(  (from.width * from.height)  <  (to.width * to.height)  ){
        return;  // Too small to copy
    }

    i8* toRedBuffPtr = to.redBuffer;
    i8* toGreenBuffPtr = to.greenBuffer;
    i8* toBlueBuffPtr = to.blueBuffer;

    i8* fromRedBuffPtr = from.redBuffer;
    i8* fromGreenBuffPtr = from.greenBuffer;
    i8* fromBlueBuffPtr = from.blueBuffer;

    for (i32 i = 0; i < width * height; i++) {
        *toRedBuffPtr = *fromRedBuffPtr;
        *toGreenBuffPtr = *fromGreenBuffPtr;
        *toBlueBuffPtr = *fromBlueBuffPtr;

        toRedBuffPtr++;
        toGreenBuffPtr++;
        toBlueBuffPtr++;

        fromRedBuffPtr++;
        fromGreenBuffPtr++;
        fromBlueBuffPtr++;
    }
}

CS_FrameBuffer::CS_FrameBuffer()
{
    curX = initCurX = CS_FONT_INIT_CUR_X;
    curY = initCurY = CS_FONT_INIT_CUR_Y;

    width = height = 1;

    AllocateBuffer(1, 1);
    ClearSelfBuffer();
}

CS_FrameBuffer::CS_FrameBuffer(i32 Width_, i32 Height_)
{
    curX = initCurX = CS_FONT_INIT_CUR_X;
    curY = initCurY = CS_FONT_INIT_CUR_Y;

    width  = Width_;
    height = Height_;

    AllocateBuffer(width, height);
    ClearSelfBuffer();
}

CS_FrameBuffer::CS_FrameBuffer(const CS_FrameBuffer& fb)
{
    width  = fb.width;
    height = fb.height;

    curX = fb.curX;
    curY = fb.curY;
    initCurX = fb.initCurX;
    initCurY = fb.initCurY;

    AllocateBuffer(width, height);
    CopySameSizeBuffer(fb, (*this));
}

CS_FrameBuffer& CS_FrameBuffer::operator=(const CS_FrameBuffer& fb)
{
    DisAllocateBuffer();

    width = fb.width;
    height = fb.height;

    curX = fb.curX;
    curY = fb.curY;
    initCurX = fb.initCurX;
    initCurY = fb.initCurY;

    AllocateBuffer(width, height);
    CopySameSizeBuffer(fb, (*this));

    return (*this);  // Support a = b = c
}

CS_FrameBuffer::~CS_FrameBuffer()
{
    DisAllocateBuffer();
}
