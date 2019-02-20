#include "Bonus.h"
#include <ctime>

using namespace std;

BonusMalusType Bonus::getType() const
{
    return _type;
}

void Bonus::move()
{
    float sinusoid = 100*sin(_current_step/20);
    _x -= _dx;
    _y = _yInitial-sinusoid;
    _current_step += 1;
}
