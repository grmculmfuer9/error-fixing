#pragma once
#include <iostream>
#include <string>
#include "Enums.cpp"
#include "Coordinates.hpp"
#include <SDL.h>
#ifndef CARDS_HPP
#define CARDS_HPP
class Cards
{
public:
    Cards()= default;
    //virtual Cards(Coordinates c, SDL_Rect src);
    std::string getID();
    virtual SDL_Rect* getsrc();
    virtual SDL_Rect* getmove();
    virtual SDL_Rect* getTreasureMove();
    virtual void setTreasuremove(const SDL_Rect& tmove); 
    virtual void setsrc(const SDL_Rect& s);
    virtual void setmove(const SDL_Rect& m);
    virtual void setID(std::string ID);
    virtual CardType getType();
    virtual void setType(CardType type);
    virtual Treasure getTreasure();
    virtual void setTreasure(Treasure t);
    virtual void setcoordinates(Coordinates c);
protected:
    Coordinates coords;
    SDL_Rect src;
    SDL_Rect move;
    SDL_Rect TreasureMove;
private:
    std::string _cardID;
    CardType _cardType;
    Treasure _treasure;
};
#endif