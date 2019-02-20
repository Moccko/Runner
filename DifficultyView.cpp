#include "DifficultyView.h"

using namespace std;

DifficultyView::DifficultyView(int w, int h, sf::RenderWindow *window) : View(w, h, window)
{
    if (!_menu_font.loadFromFile(MENU_FONT))
        cerr<<"Failed to load font file"<<endl;
    else
    {
        _location = DIFFICULTY;
        _buttons.insert(new Button(EASY, _menu_font, w/2-95, 150, WIDTH_BUTTON, HEIGHT_BUTTON, HEIGHT_BUTTON - 5, _button_released, _button_selected, _button_pressed));
        _buttons.insert(new Button(MEDIUM, _menu_font, w/2-95, 250, WIDTH_BUTTON, HEIGHT_BUTTON, HEIGHT_BUTTON - 5, _button_released, _button_selected, _button_pressed));
        _buttons.insert(new Button(HARD, _menu_font, w/2-95, 350, WIDTH_BUTTON, HEIGHT_BUTTON, HEIGHT_BUTTON - 5, _button_released, _button_selected, _button_pressed));
        _buttons.insert(new Button(INDEPENDENCEDAY, _menu_font, w/2-95, 450, WIDTH_BUTTON, HEIGHT_BUTTON, HEIGHT_BUTTON - 5, _button_released, _button_selected, _button_pressed));
    }
}

DifficultyView::~DifficultyView()
{
    for (auto button : _buttons)
        delete button;
}

void DifficultyView::draw()
{
    if (_background_music.getStatus() != sf::Music::Playing)
        _background_music.play();
    synchronize();
    _window->clear();
    _menu_background_sprite->draw(*_window);
    for (Button *b : _buttons)
        b->draw(_window);
    _window->display();
}

void DifficultyView::synchronize()
{
    for (Button *b : _buttons)
        b->inRange(_mouse_x, _mouse_y, sf::Mouse::isButtonPressed(sf::Mouse::Left), _location);
}

BUTTON DifficultyView::treatEvents()
{
    if(_window->isOpen())
    {
        sf::Event event;
        while(_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _location = QUIT;
            }
            if (event.type == sf::Event::MouseMoved)
            {
                _mouse_x = event.mouseMove.x;
                _mouse_y = event.mouseMove.y;
            }
            if (event.type == sf::Event::KeyReleased)
            {
                switch(event.key.code)
                {
                case sf::Keyboard::Escape:
                    _location = MENU;
                    break;
                default:
                    break;
                }
            }
        }
    }
    return _location;
}

void DifficultyView::reset()
{
    _location = DIFFICULTY;
}
