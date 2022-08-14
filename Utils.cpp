#include "Utils.h"
#include "App.h"

void Utils::fillRect(SDL_Rect rect,SDL_Color col)
{
    SDL_SetRenderDrawColor(App::getRenderer(),col.r,col.g,col.b,col.a);
    SDL_RenderFillRect(App::getRenderer(),&rect);
}


