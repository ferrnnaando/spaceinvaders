#include "../Engine.h"

// Why waste your brains thinking on how to solve this problem if this field of math defines this operation as one of its most basic rules? 
// All you need is to find the direction vector C, which is obtained by calculating B minus A. The difference between two positions gives us 
// the direction between the two. Yes, that easy!

void Engine::processUserEvents() {
    if(mWindow.hasFocus()) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            mWindow.close();
        }
        else { 
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) { 
                if(a_shot.getStatus() != sf::SoundSource::Playing) {
                    a_shot.play(); 
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && s_mHunter.getPosition().x > mWindow.getSize().x - mWindow.getSize().x) moveLeft = isPressed; else moveLeft = false;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && s_mHunter.getPosition().x < mWindow.getSize().x - s_mHunter.getGlobalBounds().width) moveRight = isPressed; else moveRight = false;
        }
    }
}