#include "../Engine.h"

void Engine::run() {   
    sf::Clock clock;
    while (mWindow.isOpen()) {
        sf::Time deltaTime = clock.restart();
        bool isPressed = true, moveRight = false;

        processWindowEvents();
        processUserEvents();
        update();
        render();
    } 
}
