#include "Engine.h"

void Engine::init() {
    if(!i_appIcon.loadFromFile("include/images/exec.png")) mWindow.close();
    if(!t_background_1.loadFromFile("include/images/main.png")) mWindow.close();
    if(!t_mHunter.loadFromFile("include/images/hunter.png")) mWindow.close();
}

Engine::Engine()
    : mWindow(sf::VideoMode(mWindow_sizeX, mWindow_sizeY), mWindow_title) {
        init();
        mWindow.setFramerateLimit(60);
        mWindow.setIcon(i_appIcon.getSize().x, i_appIcon.getSize().y, i_appIcon.getPixelsPtr());

        s_mHunter.setTexture(t_mHunter);
        s_mHunter.setScale(sf::Vector2f(0.05f, 0.05f));
        s_mHunter.setPosition(sf::Vector2f(mWindow.getSize().x / 2 - s_mHunter.getGlobalBounds().width / 2, mWindow.getSize().y - 160));

        s_background1.setTexture(t_background_1);
        s_background1.setScale(sf::Vector2f(static_cast<float>(mWindow.getSize().x) / t_background_1.getSize().x,
                                static_cast<float>(mWindow.getSize().y) / t_background_1.getSize().y));
    }
