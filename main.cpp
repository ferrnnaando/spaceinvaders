#include "header.h"
#include "Engine/Engine.h"

constexpr int WIN_WIDTH = 400;
constexpr int WIN_HEIGHT = 800;

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Space Invador | @ferrnnaando", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    sf::Image i_appIcon;
    i_appIcon.loadFromFile("assets/images/exec.png");
    window.setIcon(i_appIcon.getSize().x, i_appIcon.getSize().y, i_appIcon.getPixelsPtr());

    window.requestFocus();

    Engine engine = Engine(window);
    engine.run();

    return 0;
}
