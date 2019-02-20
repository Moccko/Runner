#include "GraphicElement.h"
#include <iostream>

using namespace std;

GraphicElement::GraphicElement(sf::Texture &image, int x, int y, int w, int h): sf::Sprite{image}, _x{x}, _y{y}, _w{w}, _h{h}
{
    this->setPosition(_x, _y);
}

GraphicElement::GraphicElement(sf::Texture &image, int w, int h) : sf::Sprite(image), _w(w), _h(h)
{

}

GraphicElement::GraphicElement(int w, int h) : sf::Sprite(), _w{w}, _h{h}
{

}

GraphicElement::GraphicElement(const GraphicElement &g) : sf::Sprite{*g.getTexture()}, _w{g._w}, _h{g._h}
{

}

void GraphicElement::resize(float w, float h)
{
    sf::FloatRect bb = this->getGlobalBounds();
    cout<<"graphic w : "<<bb.width<<"   graphic h : "<<bb.height<<endl;
    this->setScale (w/bb.width, h/bb.height);
}

void GraphicElement::drawGE(sf::RenderWindow *window)
{
//    this->resize(float(_w), float(_h));
//    this->setColor(sf::Color::Black);
    window->draw (*this);
}
