#include "Enemy.h"

int Enemy::getType() const
{
    return _type;
}

void Enemy::setY(int y)
{
    _y = y;
}

Enemy::Enemy(int x, int y, int w, int h, int lostHP, int type) : MovableElement{x, y-h, w, h, 0},  _lost_HP{lostHP}, _type{type}
{

}

Enemy::Enemy(int x, int w, int h, int lostHP, int type) : MovableElement{x, 0, w, h, 0},  _lost_HP{lostHP}, _type{type}
{

}

Enemy::Enemy(const Enemy &ob, int y, int dx) : MovableElement{ob._x, y-ob._h, ob._w, ob._h, dx}, _lost_HP{ob._lost_HP}, _type{ob._type}
{

}

Enemy::Enemy(const Enemy &ob, int dx) : MovableElement{ob._x, ob._y, ob._w, ob._h, dx}, _lost_HP{ob._lost_HP}, _type{ob._type}
{

}

void Enemy::move()
{
    _x -= _dx;
}

void Enemy::getInfo(int &x, int &y, int &w, int &h, int &dx, int &hp) const
{
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    dx = _dx;
    hp = _lost_HP;
}

int Enemy::getHP() const
{
    return _lost_HP;
}
