#include "../Engine.h"

void Engine::update() {
    sf::Vector2f mHunter_speed(1.5f, 0.0f);

    if(moveLeft) {
        s_mHunter.move(-mHunter_speed.x, mHunter_speed.y);
    }
    else if(moveRight) {
        s_mHunter.move(mHunter_speed.x, mHunter_speed.y);
    } 
    return;
}
