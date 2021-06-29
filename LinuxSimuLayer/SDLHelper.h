#ifndef __CSBF_LinuxSimuLayer_SDLHelper__
#define __CSBF_LinuxSimuLayer_SDLHelper__

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "../CrossBufferLayer/BasicDataTypeDeclarations.h"


class LSM_SDLHelper{
public:
    i32 screenWidth;
	i32 screenHeight;
	i32 unit;
	i32 windowWidth;
	i32 windowHeight;
	i32 leftMargin;
	i32 topMargin;

    SDL_Window* window;
    SDL_Surface* screenSurface;
    
    LSM_SDLHelper();
    void GetResolution();
    void CreateWindow(const char* title);
    void Maximize();
    void Minimize();

    SDL_Surface* LoadMedia(const char* bmpAddress);
    void ReleaseMedia(SDL_Surface* media);
    void Close();
    void BlitSurfaceHere(SDL_Surface* from);
};

#endif
