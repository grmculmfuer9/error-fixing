
#include "Player.hpp"
//#include "Coordinates.cpp"

Player::Player()
{
    
}
Player::Player(int ID, int startX, int startY) : playerID(ID), position(startX, startY) {

}

void Player::setID(int ID) {
    playerID = ID;
}

int Player::getID() const {
    return playerID;
}
// void Player::addTreasureCard(TreasureCards* Card){
//     cards.push(*Card);
// }
// bool Player::checkTreasure() {
//     //Todo: Implement logic to check for found treasure 
//     /*
//     !Return true if treasure found*/ 
// }

// TreasureCards* Player::getFound() {
//     return foundTreasure; 
// }
void Player::addCard(Treasure t)
{
    toFind.push_back(t);
}

Treasure Player::getTop()
{
    return toFind[0];
}
void Player::pop()
{
    toFind.erase(toFind.begin());
}

void Player::place_maze_card() {
    //Todo: Implement logic to place the out of range maze card on the board along with changing it's orientation
}
