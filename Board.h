#ifndef __Board__
#define __Board__
#include "Texture.h"
#include "GlobalVar.h"
#include "Card.h"


class Card;

class Board
{
public:

     Board();
    ~Board();

    void init();
    void logic();
    void restart();

    //control handler
    void doUp();
    void doDown();
    void doLeft();
    void doRight();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void sumUp();
    void sumDown();
    void sumLeft();
    void sumRight();

    void render();
    void clean();


   //setting for ending game
    bool checkWin();
    bool checkLoose();

   //generate random card
    void generateRandomCard();
private:
   bool isDo;

};
#endif // __Board__
