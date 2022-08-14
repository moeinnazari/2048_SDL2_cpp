#ifndef __Button__
#define __Button__
#include "Texture.h"
#include "App.h"

class Texture;
class Button
{
public:
    Button(std::string text="btn");
    ~Button();

    void init();
    void render(int x,int y);
    void clean();

    int getPosX() {return box.x;}
    int getPosY() {return box.y;}
    int getWidth() {return box.w;}
    int getHeight() {return box.h;}
    SDL_Rect getRect() {return box;}

    bool isInside(int x,int y);

    void hover();
    void unhover();

private:

    std::unique_ptr<Texture> m_textbtn;

    SDL_Rect box;

    SDL_Color m_colbg;
    SDL_Color m_colText;
    std::string m_text;

};
#endif // __Button__
