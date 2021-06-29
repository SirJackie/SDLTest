#ifndef __CSBF_LinuxSimuLayer_SDLHelper__
#define __CSBF_LinuxSimuLayer_SDLHelper__

#include <stdio.h>
#include <SDL.h>


class LSM_SDLHelper{
public:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    
    LSM_SDLHelper();
    void CreateWindow
    (
        int leftMargin, int topMargin, int width, int height, const char* title
    );
    SDL_Surface* LoadMedia(const char* bmpAddress);
    void ReleaseMedia(SDL_Surface* media);
    void Close();
};

#endif
