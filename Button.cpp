#include "Button.h"



//setting location and size button on screen
Button::Button(std::string text):m_text{text}
{
  m_textbtn=std::unique_ptr<Texture>(new Texture());
  m_colbg=COLOR_BUTTON_BG;
  m_colText=COLOR_BUTTON_TEXT;
}

void Button::init()
{
    m_textbtn->loadFileFromText(m_text,m_colText,FONT_BUTTON);

    box.w=m_textbtn->getWidth()+PADDING_BTN;
    box.h=m_textbtn->getHeight()+PADDING_BTN;
}


void Button::render(int x,int y)
{

    box.x=x;
    box.y=y;

    SDL_SetRenderDrawColor(App::getRenderer(),m_colbg.r,m_colbg.g,m_colbg.b,m_colbg.a);
    SDL_RenderFillRect(App::getRenderer(),&box);

    m_textbtn->render(box.x+PADDING_BTN_TEXT,box.y+PADDING_BTN_TEXT);
}

bool Button::isInside(int x,int y)
{
    if(x>getPosX() && x<getPosX()+getWidth() && y>getPosY() && y<getPosY()+getHeight())
    {
      return true;
    }
    return false;
}

void Button::hover()
{

}

void Button::unhover()
{

}


void Button::clean()
{
    m_textbtn->free();
}


Button::~Button()
{

}
