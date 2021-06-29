#include "SDLHelper.h"

SDL_Window* CreateWindow(int leftMargin, int topMargin, int width, int height, const char* title)
{
    SDL_Window* window = NULL;

    // 初始化 SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return window;
    }

    // 创建 Window
    window = SDL_CreateWindow
    (
        title,
        leftMargin,
        topMargin,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    // 检测 Window 是否可用
    if(window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return window;
    }

    return window;
}

SDL_Surface* GetWindowSurface(SDL_Window* window){
    return SDL_GetWindowSurface(window);
}

SDL_Surface* LoadMedia(const char* bmpAddress)
{
    //载入 splash image
    SDL_Surface* media = SDL_LoadBMP(bmpAddress);
    if( media == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", bmpAddress, SDL_GetError() );
    }

    return media;
}

void ReleaseMedia(SDL_Surface* media){
    SDL_FreeSurface(media);
}

void Close(SDL_Window* window)
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}
