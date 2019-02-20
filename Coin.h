#ifndef COIN_H
#define COIN_H

#include<cstdlib>
#include<ctime>
#include "MovableElement.h"

class Coin : public MovableElement
{
public:
    Coin(int x, int y, int w, int h, int dx, int value);
    int getValue() const;
    void move();

private:
    int _value;
    int _yi;
};

#endif // COIN_H
