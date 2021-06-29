#include <stdio.h>
#include <SDL.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

//Starts up SDL and creates window
//函数功能：初始化SDL并创建窗口
bool init();

//Loads media
//函数功能：加载多媒体文件
bool loadMedia();

//Frees media and shuts down SDL
//函数功能：释放多媒体文件并关闭SDL
void close();

//初始化我们将要渲染的窗口
SDL_Window* gWindow = NULL;

//The surface contained by the window
//窗口包含的surface
SDL_Surface* gScreenSurface = NULL;

//我们将会载入并在屏幕上展示的图片
SDL_Surface* gHelloWorld = NULL;

bool init()
{
    //初始化标记变量
    bool success = true;

    //初始化 SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //创建 window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //获取 window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

#define BMP_ADDR "hw.bmp"

bool loadMedia()
{
    //用来标记载入成功的变量
    bool success = true;

    //载入 splash image
    gHelloWorld = SDL_LoadBMP(BMP_ADDR);
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", BMP_ADDR, SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //释放 surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //销毁窗口
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //退出 SDL subsystems
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //初始化 SDL 并创建窗口
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //加载多媒体文件
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //应用这个图像
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
            //更新surface
            SDL_UpdateWindowSurface( gWindow );
            //保持窗口两秒
            SDL_Delay( 2000 );
        }
    }

    //释放资源并关闭SDL
    close();

    return 0;
}