#include <stdio.h>
#include "SDLHelper.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;

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
    gWindow = CreateWindow(10, 10, SCREEN_WIDTH, SCREEN_HEIGHT, "Test");
    gScreenSurface = GetWindowSurface(gWindow);

    //加载多媒体文件
    gUp = LoadMedia("./Bitmaps/Up.bmp");
    gDown = LoadMedia("./Bitmaps/Down.bmp");
    gLeft = LoadMedia("./Bitmaps/Left.bmp");
    gRight = LoadMedia("./Bitmaps/Right.bmp");
    gRelease = LoadMedia("./Bitmaps/hw.bmp");

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
        
        //应用图像
        SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );

        //更新surface
        SDL_UpdateWindowSurface( gWindow );
    }

    //释放资源并关闭SDL
    ReleaseMedia(gUp);
    ReleaseMedia(gDown);
    ReleaseMedia(gLeft);
    ReleaseMedia(gRight);
    ReleaseMedia(gRelease);

    Close(gWindow);

    return 0;
}