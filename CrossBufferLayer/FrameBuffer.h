#ifndef __CSBF_FrameBuffer__
#define __CSBF_FrameBuffer__

#include "BasicDataTypeDeclarations.h"
#include "FontSupport.h"

#define CS_FONT_INIT_CUR_X   10
#define CS_FONT_INIT_CUR_Y   10
#define CS_FONT_TEXT_WIDTH   8
#define CS_FONT_TEXT_HEIGHT  16

class CS_FrameBuffer
{
public:

    // Properties
    i32 width;
    i32 height;

    i8* redBuffer;
    i8* greenBuffer;
    i8* blueBuffer;

    i32 curX;
    i32 curY;
    i32 initCurX;
    i32 initCurY;


    // Methods
    void AllocateBuffer
         (i32 width, i32 height);
    void DisAllocateBuffer
         ();
    void ClearSelfBuffer
         ();
    void CopySameSizeBuffer
         (const CS_FrameBuffer& from, CS_FrameBuffer& to);

    CS_FrameBuffer();
    CS_FrameBuffer(i32 Width_, i32 Height_);
    CS_FrameBuffer(const CS_FrameBuffer& fb);
    CS_FrameBuffer& operator=(const CS_FrameBuffer& fb);
    ~CS_FrameBuffer();
};

#endif
