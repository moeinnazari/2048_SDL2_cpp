#include "Game.h"
#include "Utils.h"

Game::Game()
{
 m_logo=std::unique_ptr<Texture>(new Texture());
 m_scoreText=std::unique_ptr<Texture>(new Texture());
 m_highscoreText=std::unique_ptr<Texture>(new Texture());
 m_scoreInt=std::unique_ptr<Texture>(new Texture());
 m_highscoreInt=std::unique_ptr<Texture>(new Texture());
 m_newGameButton=std::unique_ptr<Button>(new Button("New Game"));
 m_Board=new Board();
}


void Game::load()
{
 m_logo->loadFileFromText("2048",COLOR_BLACK,FONT_LOGO);
 m_scoreText->loadFileFromText("score : ",COLOR_BLACK,FONT_LABEL);
 m_highscoreText->loadFileFromText("Best Score : ",COLOR_BLACK,FONT_LABEL);
 m_scoreInt->loadFileFromText(std::to_string(score),COLOR_BLACK,FONT_LABEL);
 m_highscoreInt->loadFileFromText(std::to_string(bestscore),COLOR_BLACK,FONT_LABEL);

 m_newGameButton->init();

 m_background={X_BG,Y_BG,WIDTH_BG,HEIGHT_BG};

 m_Board->init();

}




void Game::handleEvent()
{
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT:
            App::quit();
            break;
        case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_ESCAPE)
                {
                    App::quit();
                }
                if(!m_Board->checkWin() && !m_Board->checkLoose())
                {
                    if(event.key.keysym.sym==SDLK_UP && event.key.repeat==0)
                    {
                        m_Board->doUp();
                    }
                    if(event.key.keysym.sym==SDLK_DOWN && event.key.repeat==0)
                    {
                        m_Board->doDown();
                    }
                    if(event.key.keysym.sym==SDLK_LEFT && event.key.repeat==0)
                    {
                        m_Board->doLeft();
                    }
                    if(event.key.keysym.sym==SDLK_RIGHT && event.key.repeat==0)
                    {
                        m_Board->doRight();
                    }
                }


            break;
        case SDL_MOUSEBUTTONDOWN:
                 int x,y;
                 SDL_GetMouseState(&x,&y);

                 if(x > m_newGameButton->getPosX() && x < m_newGameButton->getPosX()+m_newGameButton->getWidth() &&
                     y > m_newGameButton->getPosY() && y < m_newGameButton->getPosY()+m_newGameButton->getHeight())
                 {
                     m_Board->restart();
                 }
            break;
        }
    }

}

void Game::logic()
{
  m_Board->logic();
}



void Game::render()
{
    SDL_SetRenderDrawColor(App::getRenderer(),COLOR_BG_SCREEN.r,COLOR_BG_SCREEN.g,COLOR_BG_SCREEN.b,255);
    SDL_RenderClear(App::getRenderer());

    m_logo->render(150,35);
    m_scoreText->render(350,50);
    m_highscoreText->render(350,90);
    m_scoreInt->render(500,50);
    m_highscoreInt->render(500,90);

    m_newGameButton->render(400,130);

    Utils::fillRect(m_background,COLOR_BG);
    m_Board->render();

    SDL_RenderPresent(App::getRenderer());
}



void Game::clean()
{
 m_logo->free();
 m_scoreText->free();
 m_highscoreText->free();
 m_scoreInt->free();
 m_highscoreInt->free();
 m_newGameButton->clean();
 m_Board->clean();
 delete m_Board;
}

Game::~Game()
{

}
