#ifndef ANIMATEDGRAPHICELEMENT_H
#define ANIMATEDGRAPHICELEMENT_H

#include"GraphicElement.h"
#include<vector>

class AnimatedGraphicElement : public GraphicElement
{
private:
    std::vector<sf::IntRect> _clip_rects;
    float _nb_steps;
    int _current_clip_rect;
    int _current_step;
    sf::Clock _clock;

public:
    AnimatedGraphicElement(const std::vector<sf::IntRect> &clipRects, sf::Texture &image, int x, int y, int w, int h, float nbSteps);
    AnimatedGraphicElement(const std::vector<sf::IntRect> &clipRects, sf::Texture &image, int w, int h, float nbSteps);
    AnimatedGraphicElement(const std::vector<sf::IntRect> &clipRects, int w, int h, float nbSteps);
    virtual ~AnimatedGraphicElement(){}
    virtual void drawGE(sf::RenderWindow *window);
    double getSpeed() const;
    void setSpeed(double speed);
    void setClipRects(const std::vector<sf::IntRect> &clipRects);
    std::vector<sf::IntRect> getClipRects() const;
};

#endif // ANIMATEDGRAPHICELEMENT_H
