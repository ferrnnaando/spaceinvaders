#include "../Engine.h"

void Engine::run()
{   
    while (mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    } 
}
