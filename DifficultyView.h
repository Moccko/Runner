#ifndef DIFFICULTYVIEW_H
#define DIFFICULTYVIEW_H

#include "View.h"
#include <set>

class DifficultyView : public View
{
private:
    std::set<Button *> _buttons;
    BUTTON _choice;

public:
    DifficultyView(int w, int h, sf::RenderWindow *window);
    virtual ~DifficultyView();

    void draw();
    void synchronize();
    BUTTON treatEvents();
    void updateSprite();
    void reset();
};

#endif // DIFFICULTYVIEW_H
