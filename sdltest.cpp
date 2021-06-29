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
SDL_Surface* gUp = NULL;
SDL_Surface* gDown = NULL;
SDL_Surface* gLeft = NULL;
SDL_Surface* gRight = NULL;
SDL_Surface* gRelease = NULL;

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

SDL_Surface* loadMedia(const char* bmpAddress)
{
    //载入 splash image
    SDL_Surface* media = SDL_LoadBMP(bmpAddress);
    if( media == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", bmpAddress, SDL_GetError() );
    }

    return media;
}

void releaseMedia(){
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
}

void close()
{
    //释放 surface
    SDL_FreeSurface( gUp );
    gUp = NULL;
    SDL_FreeSurface( gDown );
    gUp = NULL;
    SDL_FreeSurface( gLeft );
    gUp = NULL;
    SDL_FreeSurface( gRight );
    gUp = NULL;
    gHelloWorld = NULL;

    //销毁窗口
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //退出 SDL subsystems
    SDL_Quit();
}

//主循环标志变量
bool quit = false;

//事件handler
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


    //初始化 SDL 并创建窗口
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
        return 0;
    }

    //加载多媒体文件
    gUp = loadMedia("Up.bmp");
    gDown = loadMedia("Down.bmp");
    gLeft = loadMedia("Left.bmp");
    gRight = loadMedia("Right.bmp");
    gRelease = loadMedia("hw.bmp");

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
    close();

    return 0;
}