#ifndef __CSBF_LinuxSimuLayer_SDLHelper__
#define __CSBF_LinuxSimuLayer_SDLHelper__

#include <SDL.h>


SDL_Window* CreateWindow(int leftMargin, int topMargin, int width, int height, const char* title);
SDL_Surface* GetWindowSurface(SDL_Window* window);
SDL_Surface* LoadMedia(const char* bmpAddress);
void ReleaseMedia(SDL_Surface* media);
void Close(SDL_Window* window);

#endif
