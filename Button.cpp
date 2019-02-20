#include "Button.h"
#include <iostream>

using namespace std;

BUTTON Button::run() const
{
    return _button;
}

void Button::inRange(int x, int y, bool pressed, BUTTON &button)
{
    if (x>_x && x<_x+_w && y>_y && y<_y+_h)
    {
        if (pressed)
        {
            _clicked = true;
            _button_text.setPosition(_button_text.getPosition().x, _y + 5);
            button = _button;
        }
        else
        {
            _clicked = false;
            _in_range = true;
            _button_text.setPosition(_button_text.getPosition().x, _y);
        }
    }
    else
    {
        _clicked = false;
        _in_range = false;
        _button_text.setPosition(_button_text.getPosition().x, _y);
    }
}


bool Button::getClicked() const
{
    return _clicked;
}

Button::Button(const BUTTON &button, sf::Font &font, int x, int y, int w, int h, int h1, sf::Texture &imageReleased, sf::Texture &imageSelected, sf::Texture &imagePressed) : _button{button}
{
    _button_text = sf::Text(toString(button), font);
    _button_text.setColor(sf::Color::White);
    _button_text.setPosition(x+w/2 - (_button_text.getGlobalBounds().width)/2, y+5);
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    _released = new GraphicElement(imageReleased, x, y, w, h);
    _selected = new GraphicElement(imageSelected, x, y, w, h);
    _pressed = new GraphicElement(imagePressed, x, y + h - h1, w, h1);
    _in_range = false;
    _clicked = false;
}

Button::~Button()
{
    delete _released;
    delete _selected;
    delete _pressed;
}

void Button::draw(sf::RenderWindow *window)
{
    if (_clicked)
        _pressed->drawGE(window);
    else if (_in_range)
        _selected->drawGE(window);
    else
        _released->drawGE(window);
    window->draw(_button_text);
}
