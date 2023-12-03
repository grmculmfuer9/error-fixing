#pragma once
#include "Stack.hpp" 
#include "Coordinates.hpp"
#include "TreasureCards.cpp" 
#include "MazeCards.hpp" 
#include <vector>
#ifndef PLAYER_HPP
#define PLAYER_HPP
//Todo: define and then #include <SDL.h> 

class Player {

public:
    Player();
    Player(int ID, int startX, int startY);

    void setID(int ID);
    int getID() const;
    void addCard(Treasure t);
    Treasure getTop();
    void pop();

    //void move(SDL_KeyboardEvent event); //Todo: Handle player movement based on SDL keyboard event (to be defined) 

    //bool checkTreasure(); // Check if the player found any treasure

    //TreasureCards* getFound(); // Return array of found treasure cards
    // void addTreasureCard(TreasureCards* Card);

    void place_maze_card(); // Place the out of range maze card on the board

private:
    int playerID;
    //int treasures; if we change the amount of players who can play. Default are 4
    //Stack cards;
    Coordinates position;
    std::vector<Treasure> toFind; /*
    //! Assuming there are four players playing so each player gets 6 treasure cards */ 
    MazeCards mazecard;
};

#endif