#include "../Engine.h"

void Engine::processWindowEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
            
            default:
                break;
        }
    }
}