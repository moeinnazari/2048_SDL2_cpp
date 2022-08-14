#include "App.h"
#include "Timer.h"


SDL_Renderer* App::m_Renderer=NULL;
SDL_Window* App::m_Window=NULL;
TTF_Font* App::m_Font=NULL;
bool App::isRunning=true;

App::App()
{
 game=std::unique_ptr<Game>(new Game());
}

bool App::init()
{
    bool success=true;
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        success=false;
        std::cout<<"creation init failed\n";
    }
    else
    {
        m_Window=SDL_CreateWindow("2048",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(m_Window==NULL)
        {
            success=false;
            std::cout<<"creation window failed\n"<<SDL_GetError()<<"\n";
        }
        else
        {
            m_Renderer=SDL_CreateRenderer(m_Window,-1,SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);
            if(m_Renderer==NULL)
            {
                success=false;
                std::cout<<"creation renderer failed\n"<<SDL_GetError()<<"\n";
            }
            else
            {
                if(TTF_Init()==-1)
                {
                    success=false;
                    std::cout<<"creation ttf failed\n";
                }
                else
                {
                    SDL_SetRenderDrawColor(m_Renderer,0,0,0,255);
                }
            }
        }
    }
    return success;
}

bool App::loadFile()
{
    bool success=true;
    m_Font=TTF_OpenFont("assets/Bebas-Regular.ttf",28);
    if(m_Font==NULL)
    {
        success=false;
        std::cout<<"cant open font\n";
    }


    std::ifstream f("test.txt",std::ios::in);
    int temp;
    f>>temp;
    bestscore=temp;
    f.close();
    game->load();
    return success;
}


void App::run()
{
     Timer fps;
     while(isRunning)
     {
        fps.start();
       game->handleEvent();
       game->logic();
       game->render();

       if(fps.getTick() < SECOND_PER_FRAME)
       {
           SDL_Delay(SECOND_PER_FRAME-fps.getTick());
       }
     }
 game->clean();
}


void App::clean()
{

SDL_DestroyRenderer(m_Renderer);
m_Renderer=NULL;

SDL_DestroyWindow(m_Window);
m_Window=NULL;


TTF_CloseFont(m_Font);
m_Font=NULL;


 SDL_Quit();
 TTF_Quit();
}

App::~App()
{
 std::cout<<"exit\n";
}
