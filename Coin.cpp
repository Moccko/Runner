#include "Coin.h"
#include <cmath>
#include <ctime>

using namespace std;

Coin::Coin(int x, int y, int w, int h, int dx, int value) : MovableElement{x, y, w, h, dx}
{
    _yi = _y;
    _value = 100*value;
}

int Coin::getValue() const
{
    return _value;
}

void Coin::move()
{
    _x -= _dx;
}
