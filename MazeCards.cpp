#include "MazeCards.hpp"

MazeCards::MazeCards()=default;
MazeCards::MazeCards(Coordinates c) {
    coords = c;
}
MazeCards::MazeCards(Coordinates c, SDL_Rect s) 
{
    coords = c;
    src.x = s.x; src.y = s.y; src.w = s.w; src.h = s.h;
    move.x = c.x; move.y = c.y; move.w = move.h = 85;
    TreasureMove.x = c.x+15; TreasureMove.y = c.y + 15; TreasureMove.w = 50; TreasureMove.h = 50;
}

void MazeCards::setsrc(const SDL_Rect& s)
{
    src = s;
}
SDL_Rect* MazeCards::getsrc()
{
    return &src;
}
void MazeCards::setmove(const SDL_Rect& m)
{
    move = m;
}
SDL_Rect* MazeCards::getmove()
{
    return &move;
}
SDL_Rect* MazeCards::getTreasuremove()
{
    return &TreasureMove;
}
void MazeCards::setTreasuremove(const SDL_Rect& tmove)
{
    TreasureMove = tmove;
}

void MazeCards::setcoordinates(Coordinates c)
{
    coords.x = c.x;
    coords.y = c.y;
}

void MazeCards::setOrientation(char* arr)
{
    MazeCards::orientation = arr;
}
char* MazeCards::getOrientation()
{
    return orientation;
}