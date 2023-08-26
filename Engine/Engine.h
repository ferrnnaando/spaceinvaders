#pragma once
#include "../headers/header.h"

class Engine {
    private:
        void init();
        void processWindowEvents();
        void processUserEvents();
        void update();
        void render();

        sf::RenderWindow mWindow;
        sf::Texture t_mHunter;
        sf::Texture t_background_1;
        sf::Texture t_background_2;
        sf::Texture t_background_3;
        sf::Texture t_background_4;
        
        sf::Image i_appIcon;
        sf::Sprite s_mHunter;
        sf::Sprite s_background1;
    public:
        Engine();
        void run();
};