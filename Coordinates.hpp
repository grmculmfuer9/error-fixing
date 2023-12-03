#pragma once
class Coordinates
{
public:
    Coordinates();
    Coordinates(int xVal, int yVal);
    bool validate();
    Coordinates scaleCoordinates();
    int x;
    int y;
private:
};