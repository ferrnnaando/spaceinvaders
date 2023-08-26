#include "../Engine.h"

void Engine::update() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        mWindow.close();
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && s_mHunter.getPosition().x < mWindow.getSize().x - s_mHunter.getGlobalBounds().width) {
        s_mHunter.move(sf::Vector2f(2.5f, 0.0f));
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && s_mHunter.getPosition().x > mWindow.getSize().x - mWindow.getSize().x) {
        s_mHunter.move(sf::Vector2f(-2.5f, 0.0f));
    } 
}
