#include "GlobalVar.h"

int score=0;
int bestscore=0;

std::vector<std::vector<Card*>>   m_cards(4,std::vector<Card*>(4,new Card()));
std::vector<std::vector<int>> m_nums(4,std::vector<int>(4,0));

std::unique_ptr<Texture> m_highscoreInt=std::unique_ptr<Texture>(new Texture());
std::unique_ptr<Texture> m_scoreInt=std::unique_ptr<Texture>(new Texture());

