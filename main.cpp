#include <stdio.h>
#include "SDLHelper.h"
#include <SDL.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

LSM_SDLHelper sdlHelper;

SDL_Surface* gHelloWorld = NULL;
SDL_Surface* gUp = NULL;
SDL_Surface* gDown = NULL;
SDL_Surface* gLeft = NULL;
SDL_Surface* gRight = NULL;
SDL_Surface* gRelease = NULL;

bool quit = false;

SDL_Event e;

#define RELEASE 0
#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4

typedef int KeyboardState;
KeyboardState kb = RELEASE;

int main( int argc, char* args[] )
{
    sdlHelper.CreateWindow(10, 10, SCREEN_WIDTH, SCREEN_HEIGHT, "Test");

    //加载多媒体文件
    gUp = sdlHelper.LoadMedia("./Bitmaps/Up.bmp");
    gDown = sdlHelper.LoadMedia("./Bitmaps/Down.bmp");
    gLeft = sdlHelper.LoadMedia("./Bitmaps/Left.bmp");
    gRight = sdlHelper.LoadMedia("./Bitmaps/Right.bmp");
    gRelease = sdlHelper.LoadMedia("./Bitmaps/hw.bmp");

    gHelloWorld = gRelease;

    //当程序正在运行
    while( !quit )
    {
        //处理队列中的事件
        while( SDL_PollEvent( &e ) != 0 )
        {
            //用户选择退出
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }

            //如果用户按了按键
            if( e.type == SDL_KEYDOWN )
            {
                //依据相应的按键选择surface
                switch( e.key.keysym.sym )
                {
                case SDLK_UP:
                    kb = UP;
                    gHelloWorld = gUp;
                    break;

                case SDLK_DOWN:
                    kb = DOWN;
                    gHelloWorld = gDown;
                    break;

                case SDLK_LEFT:
                    kb = LEFT;
                    gHelloWorld = gLeft;
                    break;

                case SDLK_RIGHT:
                    kb = RIGHT;
                    gHelloWorld = gRight;
                    break;

                default:
                    break;
                }
            }

            if(e.type == SDL_KEYUP){
                gHelloWorld = gRelease;
            }
        }
        
        // //应用图像
        // SDL_BlitSurface( gHelloWorld, NULL, sdlHelper.screenSurface, NULL );

        for(int y = 0; y < sdlHelper.screenSurface->h; y++){
            for(int x = 0; x < sdlHelper.screenSurface->w; x++){
                ((int*)(sdlHelper.screenSurface->pixels))[50] = 0xFFFF0000;
            }
        }

        //更新surface
        SDL_UpdateWindowSurface(sdlHelper.window);
    }

    //释放资源并关闭SDL
    sdlHelper.ReleaseMedia(gUp);
    sdlHelper.ReleaseMedia(gDown);
    sdlHelper.ReleaseMedia(gLeft);
    sdlHelper.ReleaseMedia(gRight);
    sdlHelper.ReleaseMedia(gRelease);

    sdlHelper.Close();
    SDL_Quit();

    return 0;
}