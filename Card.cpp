#include "Card.h"
#include "App.h"
#include "Utils.h"

Card::Card(std::string text)
{
      m_text=text;
      m_bg={0,0,80,80};
      m_colbg=COLOR_CARD_0;
      //m_colText=COLOR_CARD_0;
      m_colText=COLOR_CARD_0;
      m_Texture=new Texture();
      padX=20;
      padY=20;
}

void Card::init(std::string text)
{
 m_text=text=="0"?m_text:text;
  m_Texture->loadFileFromText(m_text,m_colText,FONT_CARD);
  padX=(m_bg.w-m_Texture->getWidth())/2;
  padY=(m_bg.h-m_Texture->getHeight())/2;
}

void Card::change(std::string text)
{
    m_text=text;
    setColor(m_text);

    m_Texture->loadFileFromText(m_text,m_colText,FONT_CARD);

    Utils::fillRect(m_bg,m_colbg);

    padX=(m_bg.w-m_Texture->getWidth())/2;
    padY=(m_bg.h-m_Texture->getHeight())/2;
}

 void Card::setColor(std::string text)
{

    if(text=="0"){m_colText=COLOR_CARD_0; m_colbg=COLOR_CARD_0;}
    else if(text=="2"){m_colText=COLOR_BLACK_NUMBER; m_colbg=COLOR_CARD_2;}
    else if(text=="4"){m_colText=COLOR_BLACK_NUMBER; m_colbg=COLOR_CARD_4;}
    else if(text=="8"){m_colText=COLOR_WHITE_NUMBER; m_colbg=COLOR_CARD_8;}
    else if(text=="16"){m_colText=COLOR_WHITE_NUMBER; m_colbg=COLOR_CARD_16;}
    else if(text=="32"){m_colText=COLOR_WHITE_NUMBER; m_colbg=COLOR_CARD_32;}
    else if(text=="64"){m_colText=COLOR_WHITE_NUMBER; m_colbg=COLOR_CARD_64;}
    else if(text=="128"){m_colText=COLOR_WHITE_NUMBER; m_colbg=COLOR_CARD_128;}
    else if(text=="256"){m_colText=COLOR_WHITE_NUMBER; m_colbg=COLOR_CARD_256;}
    else if(text=="512"){m_colText=COLOR_WHITE_NUMBER; m_colbg=COLOR_CARD_512;}
    else if(text=="1024"){m_colText=COLOR_WHITE_NUMBER; m_colbg=COLOR_CARD_1024;}
    else if(text=="2048"){m_colText=COLOR_WHITE_NUMBER; m_colbg=COLOR_CARD_2048;}
    else {m_colText=COLOR_CARD_0; m_colbg=COLOR_CARD_0;}


}

void Card::render(int x,int y)
{
      m_bg.x=x;
      m_bg.y=y;


       Utils::fillRect(m_bg,m_colbg);
       m_Texture->render(x+padX,y+padY);
}

void Card::clean()
{
 m_Texture->free();
}

Card::~Card()
{

}
