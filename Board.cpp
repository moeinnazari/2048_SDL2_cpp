#include "Board.h"



Board::Board()
{
  isDo=false;

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
    moveUp();
    sumUp();
    moveUp();

    if(isDo)
    {
        generateRandomCard();
        isDo=false;
    }
}

void Board::doDown()
{
    moveDown();
    sumDown();
    moveDown();

    if(isDo)
    {
        generateRandomCard();
        isDo=false;
    }
}

void Board::doLeft()
{
    moveLeft();
    sumLeft();
    moveLeft();

    if(isDo)
    {
        generateRandomCard();
        isDo=false;
    }
}

void Board::doRight()
{
    moveRight();
    sumRight();
    moveRight();

    if(isDo)
    {
        generateRandomCard();
        isDo=false;
    }
}
void Board::moveUp()
{
   for(int i=0;i<4;i++)
   {
       for(int j=0;j<4;j++)
       {
           if(m_nums[j][i]==0)
           {
               for(int k=j+1;k<4;k++)
               {
                   if(m_nums[k][i])
                   {
                       m_nums[j][i]=m_nums[k][i];
                       m_nums[k][i]=0;
                       m_cards[j][i]->change(std::to_string(m_nums[j][i]));
                       m_cards[k][i]->change(std::to_string(m_nums[k][i]));
                       isDo=true;
                       break;

                   }
               }
           }
       }
   }
}

void Board::moveDown()
{
   for(int i=0;i<4;i++)
   {
       for(int j=3;j>=0;j--)
       {
           if(m_nums[j][i]==0)
           {
               for(int k=j-1;k>=0;k--)
               {
                   if(m_nums[k][i])
                   {
                       m_nums[j][i]=m_nums[k][i];
                       m_nums[k][i]=0;
                       m_cards[j][i]->change(std::to_string(m_nums[j][i]));
                       m_cards[k][i]->change(std::to_string(m_nums[k][i]));
                       isDo=true;
                       break;

                   }
               }
           }
       }
   }
}

void Board::moveLeft()
{
   for(int i=0;i<4;i++)
   {
       for(int j=0;j<4;j++)
       {
           if(m_nums[i][j]==0)
           {
               for(int k=j+1;k<4;k++)
               {
                   if(m_nums[i][k])
                   {
                       m_nums[i][j]=m_nums[i][k];
                       m_nums[i][k]=0;
                       m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                       m_cards[i][k]->change(std::to_string(m_nums[i][k]));
                       isDo=true;
                       break;

                   }
               }
           }
       }
   }
}

void Board::moveRight()
{
   for(int i=0;i<4;i++)
   {
       for(int j=3;j>=0;j--)
       {
           if(m_nums[i][j]==0)
           {
               for(int k=j-1;k>=0;k--)
               {
                   if(m_nums[i][k])
                   {
                       m_nums[i][j]=m_nums[i][k];
                       m_nums[i][k]=0;
                       m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                       m_cards[i][k]->change(std::to_string(m_nums[i][k]));
                       isDo=true;
                       break;

                   }
               }
           }
       }
   }
}

void Board::sumUp()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(m_nums[j][i] && m_nums[j][i]==m_nums[j+1][i])
            {
                score+=m_nums[j][i];
                m_nums[j][i]+=m_nums[j+1][i];
                m_nums[j+1][i]=0;
                isDo=true;
                m_cards[j][i]->change(std::to_string(m_nums[j][i]));
                m_cards[j+1][i]->change(std::to_string(m_nums[j+1][i]));
                m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
            }
        }
    }
}

void Board::sumDown()
{
   for(int i=0;i<4;i++)
   {
       for(int j=3;j>0;j--)
       {
           if(m_nums[j][i] && m_nums[j-1][i]==m_nums[j][i])
           {
                score+=m_nums[j][i];
                m_nums[j][i]+=m_nums[j-1][i];
                m_nums[j-1][i]=0;
                isDo=true;
                m_cards[j][i]->change(std::to_string(m_nums[j][i]));
                m_cards[j-1][i]->change(std::to_string(m_nums[j-1][i]));
                m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
           }
       }
   }
}

void Board::sumLeft()
{
  for(int i=0;i<4;i++)
  {
      for(int j=0;j<3;j++)
      {
          if(m_nums[i][j] && m_nums[i][j+1]==m_nums[i][j])
          {
                score+=m_nums[i][j];
                m_nums[i][j]+=m_nums[i][j+1];
                m_nums[i][j+1]=0;
                isDo=true;
                m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                m_cards[i][j+1]->change(std::to_string(m_nums[i][j+1]));
                m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
          }
      }
  }
}

void Board::sumRight()
{
for(int i=0;i<4;i++)
{
    for(int j=3;j>0;j--)
    {
        if(m_nums[i][j] && m_nums[i][j-1]==m_nums[i][j])
        {
                score+=m_nums[i][j];
                m_nums[i][j]+=m_nums[i][j-1];
                m_nums[i][j-1]=0;
                isDo=true;
                m_cards[i][j]->change(std::to_string(m_nums[i][j]));
                m_cards[i][j-1]->change(std::to_string(m_nums[i][j-1]));
                m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
        }
    }
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
