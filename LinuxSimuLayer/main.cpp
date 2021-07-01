#include <stdio.h>
#include "SDLHelper.h"
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "../Main.h"

// LinuxSimuLayer Variables and Declarations
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
LSM_SDLHelper sdlHelper;
bool quit = false;
SDL_Event e;

// CrossBufferLayer Variables
CS_FrameBuffer fb;
CS_Keyboard    kb;

// Time Counting Variables
csbool FirstTimeRunning;
clock_t lastTime;
clock_t thisTime;




/*
** Main Function
*/

int main( int argc, char* args[] )
{
    // sdlHelper = LSM_SDLHelper();
    sdlHelper.CreateWindow((const i8*)"Test");

    //当程序正在运行
    while(!quit)
    {
        //处理队列中的事件
        while(SDL_PollEvent(&e) != 0)
        {
            //用户选择退出
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }

            //如果用户按了按键
            if( e.type == SDL_KEYDOWN )
            {
                e.key.keysym.sym;
            }
        }

        /* Process our Game Loop */
			
        // Update Time Counting Variables
        thisTime = clock();

        // Lock System BackBuffer and Clear the FrameBuffer
        SDL_LockSurface(sdlHelper.screenSurface);
        fb = CS_FrameBuffer
        (
            sdlHelper.windowWidth, sdlHelper.windowHeight
        );

        // If it is the First Time Running
        if (FirstTimeRunning) {
            Setup(fb, kb, 0);                     // Call the Setup()  in Main.h
            FirstTimeRunning = csFalse;
        }

        // If it is not the First Time Running
        else {
            Update(fb, kb, thisTime - lastTime);  // Call the Update() in Main.h
        }

        // Release Back Buffer and Swap it as the FrontBuffer
        SDL_UnlockSurface(sdlHelper.screenSurface);

        // Paint Our FrameBuffer to System BackBuffer
        SDL_UpdateWindowSurface(sdlHelper.window);

        // Update Time Counting Variables
        // lastTime in next frame = thisTime in this frame
        lastTime = thisTime;
    }

    // After Main Loop
    sdlHelper.Close();

    return 0;
}