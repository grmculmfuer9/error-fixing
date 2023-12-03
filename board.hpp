#pragma once
#include <vector>
#include "MazeCards.hpp" 
#include "FixedMazeCards.cpp"
#include "Player.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class Board {
public:
    Board(); 
    ~Board();
    void initializeBoard(); 
    void insertMazeCard(int arrow_num); 
    void movePlayer(); 
    void moveCard();
    void rotateUsable(); 
    void DrawBoard(SDL_Renderer*gRenderer, SDL_Texture* asset1, SDL_Texture* asset2);
    void DrawTreasures(SDL_Renderer* gRenderer, SDL_Texture* asset, MazeCards* mazeCard);
    bool compareRects(SDL_Rect a, SDL_Rect b);
    void AllocateCards(Player players[]);
    void showTreasure(Player p, SDL_Renderer* gRenderer, SDL_Texture* asset);
private:
    std::vector<std::vector<Cards*>> grid;
    std::vector<FixedMaze> FM;
    std::vector<SDL_Rect> allmazecards = {

        {158,388,304,303},
        {158,753,303,304},
        {556,389,303,304},
        {556,753,304,303},

        {556, 46, 304, 303},
        {1061, 43, 303, 304},

        {1061,388,303,305},
        {1060,733,305,303},
        {1506,388,305,303},
        {1498,732,303,305}
    };

    std::vector<SDL_Rect> allTreasures =
    {
        {378,221,168,195}, //dragon
        {165,548,135,184}, //owl
        {392,520,130,219}, //lizard
        {619,524,138,219}, //witch
        {869,548,100,178}, //bug
        {381,1208,161,161}, //mouse
        {615,1235,159,106}, //bat
        {847,1235,156,108}, //spidey
        {161,1536,118,197}, //Princess
        {631,1529,128,197}, //genie
        {620,1920,152,90},  //moth
        {866,1856,128,204}, //ghost
    };

    std::vector<SDL_Rect> showTreasures = 
    {
        {125,158,213,306}, //crown
        {353,158,213,306}, //dragon
        {582,158,213,306}, //ring
        {810,158,213,306}, //books
        {125,480,213,306}, //owl
        {353,480,213,306}, //lizard
        {582,460,213,306}, //witch
        {810,480,213,306}, //bug
        {125,803,214,308}, //emerald
        {355,803,214,308}, //key
        {585,803,215,308}, //helmet
        {815,803,215,308}, //sword
        {125,1127,214,308}, //stash
        {355,1127,214,308}, //mouse
        {585,1127,215,308}, //bat
        {815,1127,215,308}, //spider
        {116,1470,219,314}, //princess
        {351,1470,219,319}, //map
        {586,1470,218,314}, //genie
        {821,1470,218,314}, //skull
        {116,1801,219,314}, //candles
        {351,1801,219,314}, //treasure_chest
        {586,1801,218,314}, //moth
        {821,1801,218,314}, //ghost
    };

    SDL_Rect ShowMover = {820, 123, 100, 145};
    Cards* usable = new MazeCards();

};
