#ifndef ENEMY_H
#define ENEMY_H

#include "Enemy.h"
#include "MovableElement.h"

class Enemy : public MovableElement
{
private:
    int _lost_HP, _type;

public:
    Enemy(int x, int y, int w, int h, int lostHP, int type);
    Enemy(int x, int w, int h, int lostHP, int type);
    Enemy(const Enemy &ob, int y, int dx);
    Enemy(const Enemy &ob, int dx);
    virtual ~Enemy(){}

    void move();
    void getInfo(int &x, int &y, int &w, int &h, int &dx, int &hp) const;
    int getHP() const;
    int gety();
    int getType() const;
    void setY(int y);
};

#endif // ENEMY_H
