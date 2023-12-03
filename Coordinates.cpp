


#include "Coordinates.hpp"
Coordinates::Coordinates()
{
    
}
Coordinates::Coordinates(int xVal, int yVal) : x(xVal), y(yVal) 
{
    
}
Coordinates Coordinates::scaleCoordinates() {
    x = x * 1000 / 3125;
    y = y * 700 / 2187;
}
bool Coordinates::validate()
{
    return false;
}

//Todo Set up validation according to board size and coordinates