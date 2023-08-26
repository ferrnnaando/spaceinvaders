#include "../Engine.h"

void Engine::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
            
            case sf::Event::LostFocus:
                std::cout << "no fyucs";
                break;
        }
    }
}