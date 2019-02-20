#ifndef CONSTANTS_H
#define CONSTANTS_H

#include<string>

///////////////////////////////
/// MUSIC / SOUND FILES     ///
///////////////////////////////

const std::string MENU_MUSIC = "Musics/champion_of_light.wav";
const std::string GAME_MUSIC = "Musics/power.ogg";
const std::string JUMP = "Sounds/jump.wav";
const std::string ENTRY_SPIKE = "Sounds/spike2.wav";
const std::string COLLISION_BERZERK = "Musics/berzerk.wav";
const std::string COLLISION_COIN = "Sounds/collision_coin.wav";
const std::string COLLISION_BONUS = "Sounds/power_up.wav";
const std::string COLLISION_MALUS = "Sounds/power_down.wav";
const std::string COLLISION_BERZERKER = "Sounds/berzerker.wav";
const std::string DEATH = "Sounds/death.wav";
const std::string COLLISION_SPIKE1 = "Sounds/spike1.wav";
const std::string COLLISION_SPIKE2 = "Sounds/spike2.wav";
const std::string COLLISION_SPIKE3 = "Sounds/spike3.wav";

///////////////////////////////
/// IMAGE FILES             ///
///////////////////////////////

const std::string BACKGROUND_IMAGE_BASIC = "Images/city_2.png";
const std::string FOREGROUND_IMAGE_BASIC = "Images/city_1.png";
const std::string MENU_BACKGROUND_IMAGE = "bg/background.png";
const std::string BUTTON_RELEASED_IMAGE = "Images/button_released.png";
const std::string BUTTON_SELECTED_IMAGE = "Images/button_selected.png";
const std::string BUTTON_PRESSED_IMAGE = "Images/button_pressed.png";
const std::string AURA = "Images/auras.png";
const std::string STICK_MAN_IMAGE = "Images/sprites_stick_man.png";
const std::string COIN_IMAGE = "Images/sprites_coins.png";
const std::string COPTER_MODE_IMAGE = "Images/sprites_flappy_copter.png";
const std::string HEAL_CARE_IMAGE = "Images/sprites_heal_care.png";
const std::string POWER_UP_IMAGE = "Images/sprites_power_ups.png";
const std::string POWER_DOWN_IMAGE = "Images/sprites_power_downs.png";
const std::string LIFE_CONTAINER = "Images/life.png";
const std::string BERZERKER_IMAGE = "Images/sprite_berzerker@64.png";
const std::string FLAPPY_COPTER_IMAGE = "Images/sprite_flappy_copter@64.png";
const std::string TEN_THE_SCORE_IMAGE = "Images/sprite_10xscore@64.png";
const std::string RED_STREAK_IMAGE = "Images/sprite_red_streak@64.png";
const std::string TIME_CONTROL_IMAGE = "Images/sprite_time_control@64.png";
const std::string SNAIL_MAN_IMAGE = "Images/sprite_snail_man@64.png";
const std::string INVERT_MOVE_IMAGE = "Images/sprite_invert_move@64.png";
const std::string HEARTS_IMAGE = "Images/sprite_hearts.png";
const std::string SPIKE1 = "Images/spike1.png";
const std::string SPIKE2 = "Images/spike2.png";
const std::string SPIKE3 = "Images/spike3.png";

///////////////////////////////
/// FONT FILES              ///
///////////////////////////////

const std::string MENU_FONT = "Fonts/BladeRunner.ttf";
const std::string GAME_FONT = "Fonts/master_of_break.ttf";

///////////////////////////////
/// TEXT FILES              ///
///////////////////////////////

const std::string SCORES = "scores.txt";

///////////////////////////////
/// NUMBERS                 ///
///////////////////////////////

const int POSITION_OBSTACLE = 700;
const int POSITION_BONUS_MALUS = 410;
const int WIDTH_BUTTON = 250;
const int HEIGHT_BUTTON = 50;
const int HEIGHT_BONUS = 50;
const int WIDTH_BONUS = 50;
const int WIDTH_STICK_MEN = 810;
const int HEIGHT_STICK_MEN = 100;
const int WIDTH_LIFE = 300;
const int HEIGHT_LIFE = 70;
const int WIDTH_COIN_IMAGE = 300;
const int HEIGHT_COIN_IMAGE = 50;
const int WIDTH_COPTER_IMAGE = 800;
const int HEIGHT_COPTER_IMAGE = 200;

enum BUTTON
{
    MENU,
    PLAY,
    RULES,
    SOUNDS,
    SETTINGS,
    INTRO,
    FINISHED,
    DIFFICULTY,
    EASY,
    MEDIUM,
    HARD,
    INDEPENDENCEDAY,
    HISCORES,
    TRANSITIONVIEW,
    PAUSE,
    CONTINUE,
    QUIT
};

enum GameState
{
    Playing,
    Paused,
    Stopped
};

#endif // CONSTANTS_H
