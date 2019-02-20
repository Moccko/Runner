#ifndef BONUS_H
#define BONUS_H

#include "MovableElement.h"
#include "BonusMalusTypes.h"
#include <cmath>

class Bonus : public MovableElement
{
private:
    BonusMalusType _type;
    int _yInitial;
    double _current_step;


public:
    Bonus(int x, int y, int w, int h, int dx, BonusMalusType type) : MovableElement{x, y, w, h, dx}, _type{type}, _yInitial{y}, _current_step{0}{}
    Bonus(const Bonus &b) : MovableElement(b._x, b._y + b._h, b._w, b._h, b._dx), _type{b._type}, _yInitial{b._yInitial}, _current_step{0} {}
    virtual ~Bonus(){}

    void move();
    BonusMalusType getType() const;
};

#endif // BONUS_H
