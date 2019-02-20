#include "Ball.h"

#include <iostream>

bool Ball::getLeft() const
{
    return _left;
}

void Ball::setLeft(bool left)
{
    _left = left;
}

bool Ball::getRight() const
{
    return _right;
}

void Ball::setRight(bool right)
{
    _right = right;
}


bool Ball::getJump() const
{
    return _jump;
}

void Ball::setJump(bool jump)
{
    _jump = jump;
}

int Ball::getX() const
{
    return _x;
}

int Ball::getY() const
{
    return _y;
}


int Ball::getdy() const
{
    return _dy;
}

void Ball::setY(int y)
{
    _y = y;
}
void Ball::move()
{
    _x+=_dx;
    _y+=_dy;
}

int Ball::getPositionY()
{
    return _y;
}

void Ball::setdY(int dy)
{
    _dy = dy;
}
