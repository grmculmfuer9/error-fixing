#pragma once
class Cqueue
{
public:
    void insertCQ(int val);
    void deleteCQ();
private:
    int cqueue[5];
    int front = -1, rear = -1, n=5;
};