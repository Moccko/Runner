#ifndef BUTTON_H
#define BUTTON_H

#include <map>
#include <string>
#include "GraphicElement.h"
#include <iostream>
#include "Constants.h"

class Button
{
private:
    BUTTON _button;
    sf::Text _button_text;
    int _x, _y, _w, _h;
    GraphicElement *_released, *_selected, *_pressed;
    bool _in_range, _clicked;

public:
    Button(const BUTTON &button, sf::Font &font, int x, int y, int w, int h, int h1, sf::Texture &imageReleased, sf::Texture &imageSelected, sf::Texture &imagePressed);
    virtual ~Button();

    BUTTON run() const;

    /*!
     * \brief Updates the button to get it Gigoubigoulahreleased, selected or pressed
     * \param x The coordinates x of the mouse
     * \param y The coordinates y of the mouse
     * \param pressed Is true if the mouse is pressed
     */
    void inRange(int x, int y, bool pressed, /*bool selected, */BUTTON &button);

    /*!
     * \brief Draws the button on the window
     * \param window The target window
     */
    void draw(sf::RenderWindow *window);

    bool getClicked() const;

    std::string _buttons_to_string[17] = {"menu", "play", "rules", "sounds", "settings", "intro", "finished", "difficulty", "easy", "medium", "hard", "independence day", "high scores", "transition","pause", "continue", "quit"};

    std::string toString(BUTTON button)
    {
        return _buttons_to_string[button];
    }
};

#endif // BUTTON_H
