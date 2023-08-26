#include "Engine.h"

Engine::Engine(sf::RenderWindow& window) { 
    mWindow = &window;

    init();

    s_background_1.setTexture(t_background_1);
    s_background_1.setScale(sf::Vector2f(static_cast<float>(mWindow->getSize().x) / t_background_1.getSize().x,
                            static_cast<float>(mWindow->getSize().y) / t_background_1.getSize().y));

    s_mHunter.setTexture(t_mHunter);
    s_mHunter.setScale(sf::Vector2f(0.13f, 0.13f));
    s_mHunter.setPosition(sf::Vector2f(mWindow->getSize().x / 2 - s_mHunter.getGlobalBounds().width / 2, mWindow->getSize().y - 160));

    a_shot.setBuffer(b_shotAudio);
}

void Engine::init() {
    if(!t_background_1.loadFromFile("assets/images/main.jpeg")) mWindow->close();
    if(!t_mHunter.loadFromFile("assets/images/mHunter.png")) mWindow->close();
    if(!t_bullet_1.loadFromFile("assets/images/ammo/bullet3.png")) mWindow->close();
    if(!b_shotAudio.loadFromFile("assets/audio/shoot.wav")) mWindow->close();
}

void Engine::processWindowEvents() {
    sf::Event event;
    while(mWindow->pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                mWindow->close();
                break;
            
            default:
                break;
        }
    }
}

// Why waste your brains thinking on how to solve this problem if this field of math defines this operation as one of its most basic rules? 
// All you need is to find the direction vector C, which is obtained by calculating B minus A. The difference between two positions gives us 
// the direction between the two. Yes, that easy!
void Engine::processUserEvents() {
    if (!mWindow->hasFocus()) {
        return;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        mWindow->close();
        return;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !LeftShot) {
        LeftShot = true;

        sf::Sprite s_bullet;
        s_bullet.setTexture(t_bullet_1);
        s_bullet.setRotation(-90);
        s_bullet.setScale(sf::Vector2f(0.023f, 0.023f));

        float x_pos = s_mHunter.getGlobalBounds().getPosition().x + ((s_mHunter.getGlobalBounds().getSize().x / 2) - (s_bullet.getGlobalBounds().getSize().x / 2)) - 2.0f;
        float y_pos = s_mHunter.getGlobalBounds().getPosition().y + 35.0f;
        s_bullet.setPosition(sf::Vector2f(x_pos, y_pos));

        _entities.push_back(s_bullet);
    } else LeftShot = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && s_mHunter.getPosition().x > mWindow->getSize().x - mWindow->getSize().x) {
        moveLeft = true;
    } else { 
        moveLeft = false;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && s_mHunter.getPosition().x < mWindow->getSize().x - s_mHunter.getGlobalBounds().width) {
        moveRight = true;
    } else {
        moveRight = false;
    }
}

void Engine::run() {   
    while (mWindow->isOpen()) {
        processWindowEvents();
        processUserEvents();
        update();
        render();
    } 
}

void Engine::update() {
    sf::Vector2f mHunter_speed(1.5f, 0.0f);

    if(LeftShot) {

        if(a_shot.getStatus() != sf::SoundSource::Playing) {
            //s_bullet_1.setPosition(sf::Vector2f(s_mHunter.getGlobalBounds().getPosition().x + 42.3, s_mHunter.getGlobalBounds().getPosition().y + 25));
            //a_shot.play(); 
        }
    } 
    
    if(moveLeft) {
        s_mHunter.move(-mHunter_speed.x, mHunter_speed.y);
    }
     if(moveRight) {
        s_mHunter.move(mHunter_speed.x, mHunter_speed.y);
    } 

    return;
}

void Engine::render() {
    mWindow->clear();
    mWindow->draw(s_background_1);

    for (sf::Sprite entity : _entities)
    {
        float y_pos = entity.getGlobalBounds().getPosition().y - 1.f;
        entity.move(0.f, y_pos);
        mWindow->draw(entity);
    }

    //maybe a while to print while the position are below to the initial y exe
    mWindow->draw(s_mHunter);
    mWindow->display();
}


