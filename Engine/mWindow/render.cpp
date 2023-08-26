#include "../Engine.h"

void Engine::render() {
    mWindow.clear();
    mWindow.draw(s_background1);
    mWindow.draw(s_mHunter);
    mWindow.display();
}
