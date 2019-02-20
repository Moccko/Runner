#include "GameView.h"
#include "Model.h"

#include <sstream>
#include <iostream>

using namespace std;

//=======================================
// Constructeur
//=======================================
GameView::GameView(const int w, const int h, sf::RenderWindow *window) : View(w, h, window), _HP(100), _actual_stage{1}
{
    _choice = CONTINUE;
    _location = CONTINUE;
    for (int i = 0; i<10; i++)
    {
        sf::IntRect rect = sf::IntRect(i*WIDTH_STICK_MEN/10,0,WIDTH_STICK_MEN/10,HEIGHT_STICK_MEN);
        _rect_ball.push_back(rect);
    }
    for (int i = 0; i<6; i++)
    {
        sf::IntRect rect = sf::IntRect(i*(WIDTH_COIN_IMAGE/6), 0, WIDTH_COIN_IMAGE/6, HEIGHT_COIN_IMAGE);
        _rect_bonus_malus.push_back(rect);
    }
    for (int i = 0; i<8; i++)
    {
        sf::IntRect rect = sf::IntRect(i*(WIDTH_COPTER_IMAGE/8), 0, WIDTH_COPTER_IMAGE/8, HEIGHT_COPTER_IMAGE/2);
        _rect_copter.push_back(rect);
    }
    for (int i = 0; i<8; i++)
    {
        sf::IntRect rect = sf::IntRect(i*(WIDTH_COPTER_IMAGE/8), HEIGHT_COPTER_IMAGE/2, WIDTH_COPTER_IMAGE/8, HEIGHT_COPTER_IMAGE);
        _rect_copter_reverse.push_back(rect);
    }
    for (int i = 0; i<4; i++)
    {
        sf::IntRect rect = sf::IntRect(i*(200/4), 0, 200/4, 80);
        _rect_obstacle1.push_back(rect);
    }
    for (int i = 0; i<4; i++)
    {
        sf::IntRect rect = sf::IntRect(i*(160/4), 0, 160/4, 100);
        _rect_obstacle2.push_back(rect);
    }
    for (int i = 0; i<4; i++)
    {
        sf::IntRect rect = sf::IntRect(i*(120/4), 0, 120/4, 120);
        _rect_obstacle3.push_back(rect);
    }
    for (int i=0; i<2; i++)
    {
        sf::IntRect rect(i*128/2, 0, 128/2, 64);
        _rect_active_bonus.push_back(rect);
    }

    for (int i=0; i<10; i++)
    {
        _backgrounds.push_back("Images/backgrounds/background"+to_string(i+1)+".png");
        _midgrounds.push_back("Images/backgrounds/midground"+to_string(i+1)+".png");
        _foregrounds.push_back("Images/backgrounds/foreground"+to_string(i+1)+".png");
    }

    for (int i=0; i<10; i++)
    {
        _background_textures.push_back(sf::Texture());
        _midground_textures.push_back(sf::Texture());
        _foreground_textures.push_back(sf::Texture());
    }

    for (int i=0; i<3; i++)
        _rect_aura.push_back(sf::IntRect(i*113, 0, 113, 150));


    if (loadResources())//charger un fichier dans le code
    {
        _obstacles_sprites.push_back(new GraphicElement{_obstacle1, _w, POSITION_OBSTACLE, 75, 200});
        _obstacles_sprites.push_back(new GraphicElement{_obstacle2, _w, POSITION_OBSTACLE, 87, 100});
        _obstacles_sprites.push_back(new GraphicElement{_obstacle3, _w, POSITION_OBSTACLE, 150, 123});
        _bonuses.push_back(_berzerker);
        _bonuses.push_back(_flappy_mode);
        _bonuses.push_back(_ten_the_score);
        _bonuses.push_back(_red_streak);
        _bonuses.push_back(_time_control);
        _bonuses.push_back(_snail_man);
        _bonuses.push_back(_invert_move);

        _font = new sf::Font();
        _font->loadFromFile(GAME_FONT);
        _background_sprite = new SlidingBackground(_background_textures[0], _w, _h, 0);
        _midground_sprite = new SlidingBackground(_midground_textures[0], _w, _h, 1);
        _foreground_sprite = new SlidingBackground(_foreground_textures[0], _w, _h, 2);
        _ball_sprite = new AnimatedGraphicElement(_rect_ball, _ball, 50, POSITION_OBSTACLE, 100, HEIGHT_STICK_MEN, 0.03);
        _aura_sprite = new AnimatedGraphicElement(_rect_aura, _aura, 50, POSITION_OBSTACLE, 70, 93, 0.05);
        _health = new sf::RectangleShape(sf::Vector2f(WIDTH_LIFE, HEIGHT_LIFE));
        _health->setPosition(_w/2-_health->getGlobalBounds().width/2, 25);
        _health->setFillColor(sf::Color::Green);
        _life_container = new GraphicElement(_life, (w-WIDTH_LIFE)/2, 25, WIDTH_LIFE, HEIGHT_LIFE);
        _pause_background = new sf::RectangleShape(sf::Vector2f(w/2, h/2));
        _pause_background->setPosition(w/4, h/4);
        _pause_background->setFillColor(sf::Color(0, 0, 0, 128));
        _active_bonus_malus = new AnimatedGraphicElement(_rect_active_bonus, WIDTH_BONUS, HEIGHT_BONUS, 0.1);
        _active_bonus_malus->setPosition(3*_w/10, 25);
        _nb_hearts = new sf::Sprite(_hearts);
        _nb_hearts->setPosition(13*_w/20, 25);
        _score = sf::Text(to_string(0), *_font, 96);
        _stage = sf::Text("Stage 1", *_font, 96);
        _stage.setPosition(sf::Vector2f(15, 15));
        _heart_sprite = new AnimatedGraphicElement(_rect_bonus_malus, _heart, 50, 50, 0.1);
        _bonus_sprite = new AnimatedGraphicElement(_rect_bonus_malus, _power_up, 50, 50, 0.1);
        _malus_sprite = new AnimatedGraphicElement(_rect_bonus_malus, _power_down, 50, 50, 0.1);
        _coin_sprite = new AnimatedGraphicElement(_rect_bonus_malus, _coin, 50, 50, 0.1);
        _background_music.setVolume(100);
        _collision_coin.setBuffer(_coin_buffer);
        _collision_berzerk.setBuffer(_berzerk_buffer);
        _collision_berzerk.setVolume(50);
        _jump.setBuffer(_jump_buffer);
        _death.setBuffer(_death_buffer);
        _collision_berzerker.setBuffer(_berzerker_buffer);
        _collision_spike1.setBuffer(_spike1_buffer);
        _collision_spike2.setBuffer(_spike2_buffer);
        _collision_spike3.setBuffer(_spike3_buffer);
        _collision_bonus.setBuffer(_bonus_buffer);
        _collision_malus.setBuffer(_malus_buffer);
        _background_music.setLoop(true);
        _background_music.play();

        _continue = new Button(CONTINUE, _menu_font, w/2 - WIDTH_BUTTON, 2*h/3, WIDTH_BUTTON, WIDTH_BUTTON, WIDTH_BUTTON - 5, _button_released, _button_selected, _button_pressed);
        _quit = new Button(MENU, _menu_font, w/2, 2*h/3, WIDTH_BUTTON, WIDTH_BUTTON, WIDTH_BUTTON - 5, _button_released, _button_selected, _button_pressed);
        _replay = new Button(PLAY, _menu_font, w/2 - WIDTH_BUTTON, 2*h/3, WIDTH_BUTTON, HEIGHT_BUTTON, HEIGHT_BUTTON - 5, _button_released, _button_selected, _button_pressed);

        //=======================================
        // PAUSE
        //=======================================

        _pause_text = sf::Text("Pause", *_font, 96);
        _game_over = sf::Text("Game Over", *_font, 96);
        _pause_text.setPosition(_w/2 - _pause_text.getGlobalBounds().width/2,_h/2 - 3*_pause_text.getGlobalBounds().height/2);
        _pause_text.setColor(sf::Color::White);
        _game_over.setPosition(_w/2 - _game_over.getGlobalBounds().width/2,_h/2 - 3*_pause_text.getGlobalBounds().height/2);
        _game_over.setColor(sf::Color::White);
    }
}

//=======================================
// Destructeur
//=======================================
GameView::~GameView(){
    if(_window != NULL)
    {
        delete _aura_sprite;
        delete _continue;
        delete _replay;
        delete _quit;
        delete _pause_background;
        delete _foreground_sprite;
        delete _midground_sprite;
        delete _background_sprite;
        delete _ball_sprite;
        delete _font;
        delete _life_container;
        delete _health;
        delete _active_bonus_malus;
        delete _nb_hearts;
        delete _heart_sprite;
        delete _coin_sprite;
        delete _bonus_sprite;
        delete _malus_sprite;
        for (GraphicElement *age : _obstacles_sprites)
            delete age;
    }
}

bool GameView::loadResources() throw()
{
    bool loaded = true;
    int i = 0;
    while (i<10 && loaded)
    {
        if (!_background_textures[i].loadFromFile(_backgrounds[i]) || !_midground_textures[i].loadFromFile(_midgrounds[i]) || !_foreground_textures[i].loadFromFile(_foregrounds[i]))
        {
            loaded = false;
            cerr<<"Failed to load background images"<<endl;
        }
        else i++;
    }

    if (!_background_music.openFromFile(GAME_MUSIC) || !_ball.loadFromFile(STICK_MAN_IMAGE) || !_coin.loadFromFile(COIN_IMAGE) || !_flappy_mode.loadFromFile(COPTER_MODE_IMAGE) || !_time_control.loadFromFile(TIME_CONTROL_IMAGE) || !_snail_man.loadFromFile(SNAIL_MAN_IMAGE) || !_invert_move.loadFromFile(INVERT_MOVE_IMAGE) || !_red_streak.loadFromFile(RED_STREAK_IMAGE) || !_ten_the_score.loadFromFile(TEN_THE_SCORE_IMAGE) || !_life.loadFromFile(LIFE_CONTAINER) || !_obstacle1.loadFromFile(SPIKE1) || !_obstacle2.loadFromFile(SPIKE2) || !_obstacle3.loadFromFile(SPIKE3) || !_heart.loadFromFile(HEAL_CARE_IMAGE) || !_power_up.loadFromFile(POWER_UP_IMAGE) || !_power_down.loadFromFile(POWER_DOWN_IMAGE) || (!_berzerker.loadFromFile(BERZERKER_IMAGE)) || (!_flappy_copter.loadFromFile(FLAPPY_COPTER_IMAGE)) || (!_hearts.loadFromFile(HEARTS_IMAGE)) || (!_coin_buffer.loadFromFile(COLLISION_COIN)) || (!_berzerk_buffer.loadFromFile(COLLISION_BERZERK)) || !_jump_buffer.loadFromFile(JUMP) || !_death_buffer.loadFromFile(DEATH) || !_berzerker_buffer.loadFromFile(COLLISION_BERZERKER) || !_spike1_buffer.loadFromFile(COLLISION_SPIKE1) || !_spike2_buffer.loadFromFile(COLLISION_SPIKE2) || !_spike3_buffer.loadFromFile(COLLISION_SPIKE3) || !_bonus_buffer.loadFromFile(COLLISION_BONUS) || !_malus_buffer.loadFromFile(COLLISION_MALUS) || !_aura.loadFromFile(AURA))
    {
        loaded = false;
        cerr<<"Error while loading images/sound files"<<endl;
    }
    if (!_button_released.loadFromFile(BUTTON_RELEASED_IMAGE) || !_button_selected.loadFromFile(BUTTON_SELECTED_IMAGE) || !_button_pressed.loadFromFile(BUTTON_PRESSED_IMAGE))
    {
        cerr << "Fichiers boutons non chargés" << endl;
        loaded = false;
    }
    return loaded;
}

//=======================================
// Accesseurs en écriture
//=======================================
void GameView::setModel(Model *model) throw()
{
    _model = model;
}

void GameView::drawObstacles() throw()
{
    for (Enemy *o : _model->getObstacles())
    {
        int id = o->getType()-1;
        _obstacles_sprites[id]->setPosition(o->getX(), o->getY());
        _obstacles_sprites[id]->drawGE(_window);
    }
}

void GameView::drawBonuses() throw()
{
    for (Bonus *b : _model->getBonuses())
        if (b->getType() == HealCare)
        {
            _heart_sprite->setPosition(b->getX(), b->getY());
            _heart_sprite->drawGE(_window);
        }
        else
        {
            _bonus_sprite->setPosition(b->getX(), b->getY());
            _bonus_sprite->drawGE(_window);
        }
}

void GameView::drawMaluses() throw()
{
    for (Malus *m : _model->getMaluses())
    {
        _malus_sprite->setPosition(m->getX(), m->getY());
        _malus_sprite->drawGE(_window);
    }
}

void GameView::drawCoins() throw()
{
    for (Coin *c : _model->getCoins())
    {
        _coin_sprite->setPosition(c->getX(), c->getY());
        _coin_sprite->drawGE(_window);
    }
}

void GameView::drawButtons() throw()
{
    if (_model->getGame() == Paused)
    {
        _continue->draw(_window);
        _quit->draw(_window);
    }
    if (_model->getGame() == Stopped)
    {
        _replay->draw(_window);
        _quit->draw(_window);
    }
}

void GameView::drawElements() throw()
{
    drawCoins();
    drawMaluses();
    drawBonuses();
    drawObstacles();
    if (_model->getBonus() == Berzerker)
    {
        int x, y;
        _model->getBallPosition(x, y);
        x -= 15; y -= 50;
        _aura_sprite->setPosition(x, y);
        _aura_sprite->drawGE(_window);
    }
    _ball_sprite->drawGE(_window);
}

void GameView::changeStage() throw()
{
    _background_sprite->setTexture(_background_textures[_actual_stage%_background_textures.size()]);
    _midground_sprite->setTexture(_midground_textures[_actual_stage%_midground_textures.size()]);
    _foreground_sprite->setTexture(_foreground_textures[_actual_stage%_foreground_textures.size()]);
}

//=======================================
// Fonction de dessin
//=======================================
void GameView::synchronize() throw()
{
    int x, y;
    _model->getBallPosition (x, y);
    _ball_sprite->setPosition (x, y);
    _model->synchroJump();
    updateActualBonusMalusSprite();
    updateSounds();
    updateStage();
    updateHealth();
    switch (_choice)
    {
    case CONTINUE:
        _model->setGame(Playing);
        break;
    case PAUSE:
        _model->setGame(Paused);
    default:
        break;
    }
}

void GameView::drawPause() throw()
{
    _continue->inRange(_mouse_x, _mouse_y, sf::Mouse::isButtonPressed(sf::Mouse::Left), _choice);
    _quit->inRange(_mouse_x, _mouse_y, sf::Mouse::isButtonPressed(sf::Mouse::Left), _choice);
    _window->draw(*_pause_background);
    _window->draw(_pause_text);
}

void GameView::drawGameOver() throw()
{
    _replay->inRange(_mouse_x, _mouse_y, sf::Mouse::isButtonPressed(sf::Mouse::Left), _choice);
    _quit->inRange(_mouse_x, _mouse_y, sf::Mouse::isButtonPressed(sf::Mouse::Left), _choice);
    _window->draw(*_pause_background);
    _window->draw(_game_over);
    _score.setCharacterSize(44);
    _score.setString("Final score : " + to_string(_model->getScore()));
    _score.setPosition((_w-_score.getGlobalBounds().width)/2, 400);
    _window->draw(_score);
}

void GameView::updateSounds() throw()
{
    if (_model->getCollisionBerzerker())
    {
        _model->setCollisionBerzerker(false);
        _collision_berzerk.play();
        _background_music.pause();
    }
    else if (_collision_berzerk.getStatus() == sf::Sound::Stopped && _background_music.getStatus() != sf::Sound::Playing)
        _background_music.play();
    switch (_model->getCollisionSpike())
    {
    case 1:
        _collision_spike1.play();
        _model->setCollisionSpike(0);
        break;
    case 2:
        _collision_spike2.play();
        _model->setCollisionSpike(0);
        break;
    case 3:
        _collision_spike3.play();
        _model->setCollisionSpike(0);
        break;
    case 4:
        _collision_berzerker.play();
        _model->setCollisionSpike(0);
    default:
        break;
    }
    if(_model->getCollisionCoin())
    {
        _collision_coin.play();
        _model->setCollisionCoin(false);
    }
    if(_model->getCollisionBonus())
    {
        _collision_bonus.play();
        _model->setCollisionBonus(false);
    }
    if(_model->getCollisionMalus())
    {
        _collision_malus.play();
        _model->setCollisionMalus(false);
    }
    if(_model->getDeath())
    {
        _death.play();
        _model->setDeath(false);
    }
}

void GameView::updateHealth() throw()
{
    _HP = _model->getHP();
    if (_model->getHP()>40)
        _health->setFillColor(sf::Color::Green);
    else
        _health->setFillColor(sf::Color::Red);
    _health->setSize(sf::Vector2f(3*_HP, 70));
    _nb_hearts->setTextureRect(sf::IntRect(0, 0, _model->getCountHP()*64, 64));
}

void GameView::reset()
{
    _location = PLAY;
}

void GameView::updateActualBonusMalusSprite() throw()
{
    switch (_model->getBonus())
    {
    case Berzerker:
        if (_ball_sprite->getTexture() != &_ball)
        {
            delete _ball_sprite;
            _ball_sprite = new AnimatedGraphicElement(_rect_ball, _ball, 100, 100, 0.1);
        }
        _ball_sprite->setColor(sf::Color::Red);
        _active_bonus_malus->setTexture(_berzerker);
        break;

    case FlappyCopter:
        if (_ball_sprite->getColor() == sf::Color::Red)
            _ball_sprite->setColor(sf::Color::White);
        if (_ball_sprite->getTexture() != &_flappy_mode)
        {
            delete _ball_sprite;
            _ball_sprite = new AnimatedGraphicElement(_rect_copter, _flappy_mode, 100, 100, 0.03);
        }
        _active_bonus_malus->setTexture(_flappy_copter);
        break;
    case RedStreak:
        if (_ball_sprite->getColor() == sf::Color::Red)
            _ball_sprite->setColor(sf::Color::White);
        _ball_sprite->setSpeed(0.005);
        if (_ball_sprite->getTexture() != &_ball)
        {
            delete _ball_sprite;
            _ball_sprite = new AnimatedGraphicElement(_rect_ball, _ball, 100, 100, 0.1);
        }
        _active_bonus_malus->setTexture(_red_streak);
        break;
    case TimeControl:
        if (_ball_sprite->getColor() == sf::Color::Red)
            _ball_sprite->setColor(sf::Color::White);
        if (_ball_sprite->getTexture() != &_ball)
        {
            delete _ball_sprite;
            _ball_sprite = new AnimatedGraphicElement(_rect_ball, _ball, 100, 100, 0.1);
        }
        _active_bonus_malus->setTexture(_time_control);
        break;
    case SnailMan:
        if (_ball_sprite->getColor() == sf::Color::Red)
            _ball_sprite->setColor(sf::Color::White);
        if (_ball_sprite->getTexture() != &_ball)
        {
            delete _ball_sprite;
            _ball_sprite = new AnimatedGraphicElement(_rect_ball, _ball, 100, 100, 0.1);
        }
        _active_bonus_malus->setTexture(_snail_man);
        break;
    case InvertMove:
        if (_ball_sprite->getColor() == sf::Color::Red)
            _ball_sprite->setColor(sf::Color::White);
        if (_ball_sprite->getTexture() != &_ball)
        {
            delete _ball_sprite;
            _ball_sprite = new AnimatedGraphicElement(_rect_ball, _ball, 100, 100, 0.1);
        }
        _active_bonus_malus->setTexture(_invert_move);
    case TenTheScore:
        if (_ball_sprite->getColor() == sf::Color::Red)
            _ball_sprite->setColor(sf::Color::White);
        if (_ball_sprite->getTexture() != &_ball)
        {
            delete _ball_sprite;
            _ball_sprite = new AnimatedGraphicElement(_rect_ball, _ball, 100, 100, 0.1);
        }
        _active_bonus_malus->setTexture(_ten_the_score);
        break;
    default:
        delete _active_bonus_malus;
        if (_ball_sprite->getColor() == sf::Color::Red)
            _ball_sprite->setColor(sf::Color::White);
        if (_ball_sprite->getTexture() != &_ball)
        {
            delete _ball_sprite;
            _ball_sprite = new AnimatedGraphicElement(_rect_ball, _ball, 100, 100, 0.1);
        }
        _active_bonus_malus = new AnimatedGraphicElement(_rect_active_bonus, WIDTH_BONUS, HEIGHT_BONUS, 0.1);
        _active_bonus_malus->setPosition(3*_w/10,25);
        break;
    }
}

void GameView::updateStage() throw()
{
    if (_actual_stage < _model->getStage())
    {
        changeStage();
        _actual_stage = _model->getStage();
    }
    _stage.setString("Stage " + to_string(_actual_stage));
    _background_sprite->setSpeed(_actual_stage);
    _midground_sprite->setSpeed(_actual_stage + 1);
    _foreground_sprite->setSpeed(_actual_stage + 2);
    _score.setString(to_string(_model->getScore()));
    _score.setPosition(_w - 20 - _score.getGlobalBounds().width, 15);
}

void GameView::draw() throw()
{
    sf::Color color = sf::Color(0, 0, 0, 255);
    _window->clear(color);
    if (_model->getBonus() == RedStreak)
        _ball_sprite->drawGE(_window);
    _background_sprite->draw(*_window);
    _midground_sprite->draw(*_window);
    _foreground_sprite->draw(*_window);
    //    _window->draw(_head);
    _window->draw(_stage);
    _window->draw(_score);
    _window->draw(*_health);
    _life_container->drawGE(_window);
    _window->draw(*_active_bonus_malus);
    _window->draw(*_nb_hearts);
    drawElements();
//    _window->setVerticalSyncEnabled(true);
    switch (_model->getGame())
    {
    case Playing:
        synchronize();
        break;
    case Paused:
        drawPause();
        break;
    case Stopped:
        drawGameOver();
        break;
    }
    drawButtons();
    _window->display();
}

//=======================================
// Traitement des evenements
//=======================================
BUTTON GameView::treatEvents() throw()
{
    if(_window->isOpen())
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _location = QUIT;
            if (_choice == MENU)
                _location = MENU;
            if (_choice == PLAY)
                _location = PLAY;
            if (_choice == CONTINUE)
                _model->setGame(Playing);
            if (event.type == sf::Event::MouseMoved)
            {
                _mouse_x = event.mouseMove.x;
                _mouse_y = event.mouseMove.y;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                switch(event.key.code)
                {
                case sf::Keyboard::Escape:
                    if (_model->getGame() == Playing)
                        _choice = PAUSE;
                    else
                        _choice = CONTINUE;
                    break;
                case sf::Keyboard::Right:
                    _model->getBall ()->setRight(true);
                    if (_model->getBonus() == FlappyCopter)
                        if (_ball_sprite->getClipRects() != _rect_copter)
                            _ball_sprite->setClipRects(_rect_copter);
                    break;
                case sf::Keyboard::Left:
                    _model->getBall()->setLeft(true);
                    if (_model->getBonus() == FlappyCopter)
                        if (_ball_sprite->getClipRects() != _rect_copter_reverse)
                            _ball_sprite->setClipRects(_rect_copter_reverse);
                    break;
                case sf::Keyboard::Space:
                    _model->jump();
                    _jump.play();
                    break;
                case sf::Keyboard::Up:
                    _model->jump();
                    _jump.play();
                    break;
                case sf::Keyboard::Down:
                    if (_model->getBonus() == TimeControl)
                        _model->setStopped(true);
                    break;
                default:
                    break;
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                switch(event.key.code)
                {
                case sf::Keyboard::Left:
                    _model->getBall()->setLeft(false);
                    break;
                case sf::Keyboard::Right:
                    _model->getBall()->setRight(false);
                    break;
                case sf::Keyboard::Down:
                    _model->setStopped(false);
                    break;
                default:
                    break;
                }
            }
        }
    }
    return _location;
}

