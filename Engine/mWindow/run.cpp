#include "../Engine.h"

void Engine::run()
{   
    while (mWindow.isOpen())
    {
        processWindowEvents();
        processUserEvents();
        update();
        render();
    } 
}
