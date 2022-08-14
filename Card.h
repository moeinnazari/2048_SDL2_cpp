#ifndef __Card__
#define __Card__
#include "GlobalVar.h"
#include "Texture.h"

class Texture;
class Card
{
public:
    Card(std::string text="1");
    ~Card();

    void init(std::string text="0");
    void change(std::string text);
    void render(int x,int y);
    void clean();
    void setColor(std::string text);

private:
    SDL_Rect m_bg;
    SDL_Color m_colbg;
    SDL_Color m_colText;
    std::string m_text;
    Texture* m_Texture;
    int padX,padY;
};

#endif // __Card__
