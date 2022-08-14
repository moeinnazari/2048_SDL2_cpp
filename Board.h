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


    void render();
    void clean();


   //setting for ending game
    bool checkWin();
    bool checkLoose();

   //generate random card
    void generateRandomCard();
private:


};
#endif // __Board__
