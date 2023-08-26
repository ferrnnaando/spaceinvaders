#pragma once
#include "../headers/header.h"

class Engine {
    public:
        Engine();
        void run();
    private:
        void init();
        void processWindowEvents();
        void processUserEvents();
        void update();
        void render();

        sf::RenderWindow mWindow;
        sf::Clock mClock;

        sf::Texture t_mHunter;
        sf::Texture t_background_1;
        sf::Texture t_background_2;
        sf::Texture t_background_3;
        sf::Texture t_background_4;
        sf::Texture t_bullet_1;
        
        sf::Image i_appIcon;
        
        sf::SoundBuffer b_shotAudio;
        sf::Sound a_shot;

        sf::Sprite s_mHunter;
        sf::Sprite s_background_1;

        sf::Texture t_background1;
        bool moveLeft = false;
        bool moveRight = false;
        bool isPressed = true;
};