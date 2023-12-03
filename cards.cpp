#include "cards.hpp"

std::string Cards::getID()
{
    return _cardID;
}
void Cards::setID(std::string ID)
{
    _cardID = ID;
}
CardType Cards::getType()
{
    return _cardType;
}
void Cards::setType(CardType type)
{
    _cardType = type;
}
Treasure Cards::getTreasure()
{
    return _treasure;
}
void Cards::setTreasure(Treasure t)
{
    _treasure = t;
}
void Cards::setsrc(const SDL_Rect& s)  
{
    src = s;
}
SDL_Rect* Cards::getsrc()
{
    return &src;
}
void Cards::setmove(const SDL_Rect& m)
{
    move = m;
}
SDL_Rect* Cards::getmove()
{
    return &move;
}
SDL_Rect* Cards::getTreasureMove()
{
    return &TreasureMove;
}
void Cards::setTreasuremove(const SDL_Rect& tmove)
{
    TreasureMove = tmove;
}

void Cards::setcoordinates(Coordinates c)
{}
