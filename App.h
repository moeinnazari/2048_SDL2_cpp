#ifndef __App__
#define __App__
#include "GlobalVar.h"
#include "Game.h"


class Game;
class App
{
public:
    App();
    ~App();


    bool init();
    bool loadFile();
    void run();
    void clean();

    static SDL_Renderer* getRenderer() {return m_Renderer;}
    static SDL_Window* getWindow() {return m_Window;}
    static TTF_Font* getFont() {return m_Font;}

    static void quit(){isRunning=false;}
private:



    static  SDL_Renderer* m_Renderer;
    static  SDL_Window* m_Window;
    static  TTF_Font* m_Font;


    static bool isRunning;

    std::unique_ptr<Game> game;


};
#endif // __App__
