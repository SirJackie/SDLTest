#include "SDLHelper.h"
#include <SDL.h>

LSM_SDLHelper::LSM_SDLHelper(){
    window = NULL;
    screenSurface = NULL;

    SDL_DisplayMode m;

    // Make sure we have the right to get resolution (important!)
    system("sudo chmod 777 /dev/fb0");

    // Get Resolution
    SDL_GetDesktopDisplayMode(0, &m);

    screenWidth = m.w;
    screenHeight = m.h;

    windowWidth = 640;
    windowHeight = 480;
    leftMargin = 10;
    topMargin = 10;

    printf("%d, %d\n", m.w, m.h);

    // unit = screenHeight / 30;

	// windowHeight = 26 * unit;
	// windowWidth = CS_iclamp(0, windowHeight / 9 * 16, screenWidth - 10);

	// leftMargin = (screenWidth - windowWidth) / 2;
	// topMargin = (screenHeight - windowHeight) / 2;
}

void LSM_SDLHelper::GetResolution(){
    ;
}

void LSM_SDLHelper::CreateWindow(const char* title){
    window = NULL;
    screenSurface = NULL;

    // 初始化 SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    // 创建 Window
    window = SDL_CreateWindow
    (
        title,
        leftMargin,
        topMargin,
        windowWidth,
        windowHeight,
        SDL_WINDOW_SHOWN
    );

    // 检测 Window 是否可用
    if(window == NULL){
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }

    screenSurface = SDL_GetWindowSurface(window);
    if(screenSurface == NULL){
        printf("ScreenSurface could not be gotten! SDL_Error: %s\n", SDL_GetError());
    }
}

void LSM_SDLHelper::Maximize(){
    SDL_MaximizeWindow(window);
}

void LSM_SDLHelper::Minimize(){
    SDL_MinimizeWindow(window);
}

SDL_Surface* LSM_SDLHelper::LoadMedia(const char* bmpAddress)
{
    //载入 splash image
    SDL_Surface* media = SDL_LoadBMP(bmpAddress);
    if( media == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", bmpAddress, SDL_GetError() );
    }

    return media;
}

void LSM_SDLHelper::ReleaseMedia(SDL_Surface* media){
    SDL_FreeSurface(media);
}

void LSM_SDLHelper::Close()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void LSM_SDLHelper::BlitSurfaceHere(SDL_Surface* from){
    SDL_BlitSurface( from, NULL, screenSurface, NULL );
}
