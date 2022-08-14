#include "Board.h"



Board::Board()
{


   for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
    {
        m_cards[i][j]=new Card("0");
    }
   }



}

void Board::init()
{
   for(int i=0;i<4;i++){
    for(int j=0;j<4;j++)
    {
        m_cards[i][j]->init(std::to_string(m_nums[i][j]));
    }
   }
   generateRandomCard();
   generateRandomCard();
}

void Board::restart()
{
   for(int i=0;i<4;i++)
   {
       for(int j=0;j<4;j++)
       {
           m_nums[i][j]=0;
           m_cards[i][j]->change(std::to_string(m_nums[i][j]));
       }
   }

   generateRandomCard();
   generateRandomCard();
   score=0;
   m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
}

void Board::logic()
{
    if(score>bestscore)
    {
        bestscore=score;
        m_highscoreInt->loadFileFromText(std::to_string(bestscore),COLOR_BLACK,FONT_LABEL);
        std::fstream f("test.txt",std::ios::out);
        f<<bestscore;
        f.close();
    }
}



bool Board::checkWin()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
    {
        if(m_nums[i][j]==2048)
        {
            return true;
        }
    }
    return false;
}

bool Board::checkLoose()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
    {
        if(m_nums[i][j]==0)
        {
            return false;
        }
    }
    return true;
}

void Board::generateRandomCard()
{
    int i=std::rand()%4;
    int j=std::rand()%4;
    if(m_nums[i][j]==0)
    {
        m_nums[i][j]=2;
        m_cards[i][j]->change(std::to_string(m_nums[i][j]));
    }
    else
    {
        generateRandomCard();
    }
}

void Board::doUp()
{
    bool isDo=false;
    for(int j=0;j<4;j++)
    {
        for(int i=0;i<3;i++)
        {
            for(int k=i+1;k<4;k++)
                {
                    if(m_nums[k][j]>0)
                    {
                      if(m_nums[i][j]==0)
                      {

                        m_nums[i][j]=m_nums[k][j];
                        m_nums[k][j]=0;
                        isDo=true;
                        m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                        m_cards[k][j]->change(std::to_string(m_nums[k][j]));

                      }
                      if(m_nums[i][j]==m_nums[k][j])
                      {
                            score+=m_nums[k][j];
                            m_nums[i][j]+=m_nums[k][j];
                            m_nums[k][j]=0;
                            isDo=true;
                            m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                            m_cards[k][j]->change(std::to_string(m_nums[k][j]));
                            m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
                      }
                    break;
                    }
                }
            }
    }

    if(isDo)
    {
        generateRandomCard();
    }
}

void Board::doDown()
{
    bool isDo=false;
    for(int j=0;j<4;j++)
    {
        for(int i=3;i>0;i--)
        {
            for(int k=i-1;k>=0;k--)
            {
                if(m_nums[k][j]>0)
                {
                    if(m_nums[i][j]==0)
                    {
                            m_nums[i][j]=m_nums[k][j];
                            m_nums[k][j]=0;
                            m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                            m_cards[k][j]->change(std::to_string(m_nums[k][j]));
                            isDo=true;
                    }
                    if(m_nums[i][j]==m_nums[k][j])
                    {
                        score+=m_nums[k][j];
                        m_nums[i][j]+=m_nums[k][j];
                        m_nums[k][j]=0;
                        isDo=true;
                        m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                        m_cards[k][j]->change(std::to_string(m_nums[k][j]));
                        m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
                    }
                    break;

                }
            }
        }
    }

    if(isDo)
    {
        generateRandomCard();
    }
}
void Board::doLeft()
{
        bool isDo=false;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=j+1;k<4;k++)
                {
                    if(m_nums[i][k]>0)
                    {
                        if(m_nums[i][j]==0)
                        {
                            m_nums[i][j]=m_nums[i][k];
                            m_nums[i][k]=0;
                            m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                            m_cards[i][k]->change(std::to_string(m_nums[i][k]));
                            isDo=true;
                        }
                        if(m_nums[i][j]==m_nums[i][k])
                        {
                            score+=m_nums[i][k];
                            m_nums[i][j]*=2;
                            m_nums[i][k]=0;
                            m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                            m_cards[i][k]->change(std::to_string(m_nums[i][k]));
                            m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
                            isDo=true;
                        }
                        break;
                    }


                }

            }
        }
        if(isDo)
        {
            generateRandomCard();
        }
}
void Board::doRight()
{
       bool isDo=false;
       for(int i=0;i<4;i++)
       {
           for(int j=3;j>0;j--)
           {
               for(int k=j-1;k>=0;k--)
               {
                   if(m_nums[i][k]>0)
                   {
                       if(m_nums[i][j]==0)
                       {
                            m_nums[i][j]=m_nums[i][k];
                            m_nums[i][k]=0;
                            m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                            m_cards[i][k]->change(std::to_string(m_nums[i][k]));
                            isDo=true;
                       }
                       if(m_nums[i][j]==m_nums[i][k])
                       {
                            score+=m_nums[i][k];
                            m_nums[i][j]*=2;
                            m_nums[i][k]=0;
                            m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                            m_cards[i][k]->change(std::to_string(m_nums[i][k]));
                            m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
                            isDo=true;
                       }
                        break;

                   }

               }
           }
       }
        if(isDo)
        {
            generateRandomCard();
        }
}


void Board::render()
{

    for(int i=0;i<4;i++)
  {
      for(int j=0;j<4;j++)
      {
          m_cards[i][j]->render(X_BG+20+95*j,Y_BG+20+95*i);
      }
  }

}

void Board::clean()
{

   for(int i=0;i<4;i++)
  {
      for(int j=0;j<4;j++)
      {
          m_cards[i][j]->clean();
      }
  }


}

Board::~Board()
{

}
