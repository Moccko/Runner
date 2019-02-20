#include "AnimatedGraphicElement.h"
#include<iostream>

void AnimatedGraphicElement::setClipRects(const std::vector<sf::IntRect> &clipRects)
{
    _clip_rects = clipRects;
    _current_step = 0;
}

std::vector<sf::IntRect> AnimatedGraphicElement::getClipRects() const
{
    return _clip_rects;
}

AnimatedGraphicElement::AnimatedGraphicElement(const std::vector<sf::IntRect> &clipRects, sf::Texture &image, int x, int y, int w, int h, float nbSteps) : GraphicElement{image, x, y, w, h},  _clip_rects{clipRects}, _nb_steps{nbSteps}, _current_clip_rect{0}, _current_step{0}
{

}

AnimatedGraphicElement::AnimatedGraphicElement(const std::vector<sf::IntRect> &clipRects, sf::Texture &image, int w, int h, float nbSteps) : GraphicElement{image, w, h},  _clip_rects{clipRects}, _nb_steps{nbSteps}, _current_clip_rect{0}, _current_step{0}
{

}

AnimatedGraphicElement::AnimatedGraphicElement(const std::vector<sf::IntRect> &clipRects, int w, int h, float nbSteps) : GraphicElement{ w, h},  _clip_rects{clipRects}, _nb_steps{nbSteps}, _current_clip_rect{0}, _current_step{0}
{

}

void AnimatedGraphicElement::drawGE(sf::RenderWindow *window)
{
    setTextureRect(_clip_rects[_current_clip_rect]);
//    std::cout<<"resize dans methode draw _w="<<_w<<" _h="<<_h<<std::endl;
//    this->resize(float(_w), float(_h));
    window->draw(*this);

    if (_clip_rects[_current_clip_rect] != _clip_rects.back())
    {
        if(_clock.getElapsedTime().asSeconds()>_nb_steps)
        {
            _current_clip_rect++;
            _current_step = 0;
            _clock.restart();
        }
        else
            _current_step++;
    }
    else
        _current_clip_rect = 0;
}

double AnimatedGraphicElement::getSpeed() const
{
    return _nb_steps;
}

void AnimatedGraphicElement::setSpeed(double speed)
{
    _nb_steps = speed;
}
