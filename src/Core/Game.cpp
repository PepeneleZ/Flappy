#include "Core/Game.hpp"

Game::Game()
    : window(sf::VideoMode({1024u, 768u}), "Flappy") 
    , bg(textureManager, renderer)
    , ground(textureManager, renderer, collisionManager)
    , player(textureManager, renderer, eventDispatcher, collisionManager)
    , pipePair(textureManager, renderer, eventDispatcher, collisionManager)
    , collisionManager(eventDispatcher)
{


}

void Game::run() {
    while(window.isOpen()){
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        update(deltaTime);
        
        render();
    }
}

void Game::update(float deltaTime) {
    collisionManager.checkCollisions();
    
    player.update(deltaTime);
    pipePair.update(deltaTime);
    
}

void Game::render() {
    window.clear();

    renderer.draw(window);

    window.display();
}