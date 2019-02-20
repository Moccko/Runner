#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <SFML/Graphics.hpp>

class GraphicElement : public sf::Sprite
{
protected:
    int _x, _y, _w, _h;

public:
    GraphicElement(sf::Texture &image, int x, int y, int w, int h);
    GraphicElement(sf::Texture &image, int w, int h);
    GraphicElement(int w, int h);
    GraphicElement(const GraphicElement &g);
    virtual ~GraphicElement(){}
    void resize(float w, float h);
    virtual void drawGE(sf::RenderWindow *window);
};

#endif // GRAPHICELEMENT_H
