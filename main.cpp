#include "headers/header.h"
#include "Engine/Engine.h"

/*template<typename t>
void funcion(t&& arg) requires (std::is_same_v<t, int>) {

}*/


int main() {
    Engine game;
    game.run();
    return 0;
}