#include <stdio.h>
#include "SDLHelper.h"
#include <SDL.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

LSM_SDLHelper sdlHelper;

bool quit = false;
SDL_Event e;
SDL_DisplayMode* dmode = NULL;

int main( int argc, char* args[] )
{
    printf("%d\n", SDL_GetDesktopDisplayMode(SDL_GetNumVideoDrivers(), dmode));

    printf("%d\n", SDL_GetNumVideoDrivers());
    printf("Width: %d; Height: %d;\n", dmode->w, dmode->h);

    sdlHelper.CreateWindow(10, 10, SCREEN_WIDTH, SCREEN_HEIGHT, "Test");

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
        
        // 主程序
        SDL_LockSurface(sdlHelper.screenSurface);

        for(int y = 0; y < sdlHelper.screenSurface->h; y++){
            for(int x = 0; x < sdlHelper.screenSurface->w; x++){
                ((int*)(sdlHelper.screenSurface->pixels))[y * (sdlHelper.screenSurface->pitch / 4) + x] = 0xFFFF0000;
            }
        }

        SDL_UnlockSurface(sdlHelper.screenSurface);
        SDL_UpdateWindowSurface(sdlHelper.window);
    }

    // After Main Loop
    sdlHelper.Close();

    return 0;
}