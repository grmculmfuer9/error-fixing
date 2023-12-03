
#include "cards.hpp"
class FixedMaze : public Cards
{
public:
    FixedMaze(Coordinates c) : coords(c)
    {}
    FixedMaze(){}
    Coordinates coords;
private:
};