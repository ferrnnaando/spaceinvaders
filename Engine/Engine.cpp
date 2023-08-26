#include "Engine.h"

void Engine::init() {
    if(!i_appIcon.loadFromFile("include/images/exec.png")) mWindow.close();
    if(!t_background_1.loadFromFile("include/images/main.jpeg")) mWindow.close();
    if(!t_mHunter.loadFromFile("include/images/mHunter.png")) mWindow.close();
    if(!b_shotAudio.loadFromFile("include/audio/shoot.wav")) mWindow.close(); //both b
    if(!t_bullet_1.loadFromFile("include/images/ammo/bullet3.png")) mWindow.close();
}

Engine::Engine()
    : mWindow(sf::VideoMode(mWindow_sizeX, mWindow_sizeY), mWindow_title) {        
        init();
        mWindow.setIcon(i_appIcon.getSize().x, i_appIcon.getSize().y, i_appIcon.getPixelsPtr());
        mWindow.setFramerateLimit(60);
        mWindow.setVerticalSyncEnabled(true);

        s_mHunter.setTexture(t_mHunter);
        s_mHunter.setScale(sf::Vector2f(0.13f, 0.13f));
        s_mHunter.setPosition(sf::Vector2f(mWindow.getSize().x / 2 - s_mHunter.getGlobalBounds().width / 2, mWindow.getSize().y - 160));

        s_background_1.setTexture(t_background_1);
        s_background_1.setScale(sf::Vector2f(static_cast<float>(mWindow.getSize().x) / t_background_1.getSize().x,
                                static_cast<float>(mWindow.getSize().y) / t_background_1.getSize().y));

        a_shot.setBuffer(b_shotAudio);
    }
