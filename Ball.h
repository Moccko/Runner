#ifndef BALL_H
#define BALL_H

#include "MovableElement.h"
#include<iostream>

using namespace std;

class Ball : public MovableElement
{
private:
    int _dy;
    bool _jump;
    bool _right, _left;

public:
    Ball(int x, int y, int w, int h) : MovableElement{x, y-h, w, h, 0}, _jump{false}, _right{false}, _left{false}{_dy=0;}
    virtual ~Ball(){}
    void saut();
    void move();
    int getPositionY();
    void setY(int y);
    int getdy() const;
    void setdY(int dy);
    bool getLeft() const;
    void setLeft(bool left);
    bool getRight() const;
    void setRight(bool right);
    bool getJump() const;
    void setJump(bool jump);
    int getX() const;
    int getY() const;
};

#endif // BALL_H
