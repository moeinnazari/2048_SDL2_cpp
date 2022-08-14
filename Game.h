#ifndef __Game__
#define __Game__
#include "App.h"
#include "Texture.h"
#include "Button.h"
#include "Card.h"
#include "Board.h"

class Board;
class Button;
class Texture;
class Game
{
public:
    Game();
    ~Game();

    void load();
    void handleEvent();
    void logic();
    void render();
    void clean();

private:
   SDL_Event event;
   SDL_Rect  m_background;
  std::unique_ptr<Texture> m_logo;
  std::unique_ptr<Texture> m_scoreText;
  std::unique_ptr<Texture> m_highscoreText;
  std::unique_ptr<Button> m_newGameButton;
  Board* m_Board;


};
#endif // __Game__
