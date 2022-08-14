#ifndef __GlobalVar__
#define __GlobalVar__
#include "SDL2/include/SDL2/SDL.h"
#include "SDL2/include/SDL2/SDL_ttf.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Texture.h"
#include "Card.h"

//class Card;
class Texture;
class Card;

//setting for windowshow
const int SCREEN_WIDTH=700;
const int SCREEN_HEIGHT=600;
const int FPS=30;
const int SECOND_PER_FRAME=33; //(int)1000/FPS
const int WIDTH_BG=400;
const int HEIGHT_BG=400;
const int X_BG=150;
const int Y_BG=190;


//fonts
const int FONT_LABEL=24;
const int FONT_CARD=34;
const int FONT_LOGO=72;
const int FONT_BUTTON=24;
//for padding button newgame
const int PADDING_BTN=20;
const int PADDING_BTN_TEXT=10;

//colors
const SDL_Color COLOR_BG_SCREEN={255,248,239,255};
const SDL_Color COLOR_BLACK={126,120,114,255};
const SDL_Color COLOR_BLACK_NUMBER={119,110,101,255};
const SDL_Color COLOR_WHITE_NUMBER={249,246,242,255};

const SDL_Color COLOR_BUTTON_BG={143,122,102,255};
const SDL_Color COLOR_BUTTON_TEXT={249,246,242,255};

const SDL_Color COLOR_BG={187,173,160,255};
const SDL_Color COLOR_CARD_0={205,193,180,255};
const SDL_Color COLOR_CARD_2={238,228,218,255};
const SDL_Color COLOR_CARD_4={237, 224, 200,255};
const SDL_Color COLOR_CARD_8={242, 177, 121,255};
const SDL_Color COLOR_CARD_16={245, 149, 99,255};
const SDL_Color COLOR_CARD_32={246, 124, 95,255};
const SDL_Color COLOR_CARD_64={246, 94, 59,255};
const SDL_Color COLOR_CARD_128={237, 207, 114,255};
const SDL_Color COLOR_CARD_256={237, 204, 97,255};
const SDL_Color COLOR_CARD_512={237, 200, 80,255};
const SDL_Color COLOR_CARD_1024={237, 197, 63,255};
const SDL_Color COLOR_CARD_2048={237, 194, 46,255};

//save high score
extern int score;
extern int bestscore;
extern std::unique_ptr<Texture> m_highscoreInt;
extern std::unique_ptr<Texture> m_scoreInt;

extern std::vector<std::vector<Card*>> m_cards;
extern std::vector<std::vector<int>> m_nums;

#endif // __GlobalVar__
