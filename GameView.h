#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "View.h"
#include "Model.h"

class Model;

class GameView : public View {
private:
    int _HP, _actual_stage;
    Model * _model;
    sf::Font * _font;

//    GraphicElement _pause_background;

    sf::Texture _background;
    sf::Texture _foreground;
    SlidingBackground *_background_sprite;
    SlidingBackground *_midground_sprite;
    SlidingBackground *_foreground_sprite;
    sf::Texture _ball;
    sf::Texture _flappy_mode;
    sf::Texture _coin;
    sf::Texture _heart;
    sf::Texture _power_up;
    sf::Texture _power_down;
    sf::Texture _berzerker;
    sf::Texture _flappy_copter;
    sf::Texture _hearts;
    sf::Texture _ten_the_score;
    sf::Texture _snail_man;
    sf::Texture _invert_move;
    sf::Texture _time_control;
    sf::Texture _red_streak;
    sf::Texture _obstacle1;
    sf::Texture _obstacle2;
    sf::Texture _obstacle3;
    sf::Texture _bonus1;
    sf::Texture _bonus2;
    sf::Texture _bonus3;
    sf::Texture _life;
    sf::Texture _aura;
    std::vector<std::string> _backgrounds, _midgrounds, _foregrounds;
    std::vector<sf::Texture> _background_textures, _midground_textures, _foreground_textures;
    sf::Text _head, _stage, _score, _pause_text, _game_over;
    AnimatedGraphicElement *_ball_sprite, *_heart_sprite, *_bonus_sprite, *_malus_sprite, *_coin_sprite, *_active_bonus_malus, *_aura_sprite;
    GraphicElement *_life_container;
    sf::Sprite *_nb_hearts;
    sf::RectangleShape *_health, *_pause_background;
    std::vector<sf::IntRect> _rect_ball, _rect_bonus_malus, _rect_copter, _rect_copter_reverse, _rect_obstacle1, _rect_obstacle2, _rect_obstacle3, _rect_active_bonus, _rect_aura;
    std::vector<GraphicElement *> _obstacles_sprites;
    std::vector<sf::Texture> _bonuses;
    /*!
     * \brief The container of the background music file
     */
    sf::Music _background_music;
    /*!
     * \brief The files for collisions' sounds
     */
    sf::SoundBuffer _coin_buffer, _berzerk_buffer, _jump_buffer, _death_buffer, _berzerker_buffer, _spike1_buffer, _spike2_buffer, _spike3_buffer, _bonus_buffer, _malus_buffer;
    /*!
     * \brief The containers of the collisions's sounds files
     */
    sf::Sound _collision_coin, _collision_berzerk, _jump, _death, _collision_berzerker, _collision_spike1, _collision_spike2, _collision_spike3, _collision_bonus, _collision_malus;

    int _mouse_x, _mouse_y;
    BUTTON _choice;
    sf::Texture _button_released, _button_selected, _button_pressed;
    Button *_continue;
    Button *_quit;
    Button *_replay;

public:
    GameView(const int w, const int h, sf::RenderWindow *window);
    virtual ~GameView();

    bool loadResources() throw();
    void setModel(Model *model) throw();
    void synchronize() throw();
    void drawPause() throw();
    void drawGameOver() throw();
    void drawObstacles() throw();
    void drawBonuses() throw();
    void drawMaluses() throw();
    void drawCoins() throw();
    void drawButtons() throw();
    void drawElements() throw();
    void changeStage() throw();
    void draw() throw();
    BUTTON treatEvents() throw();
    void updateActualBonusMalusSprite() throw();
    void updateStage() throw();
    /*!
     * \brief Adjust the sound to pause Background Music if the collision music of the Berzerker Bonus is active
     */
    void updateSounds() throw();
    void updateHealth() throw();
    void reset();
};

#endif // GAMEVIEW_H
