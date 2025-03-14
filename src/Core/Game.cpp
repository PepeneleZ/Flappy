#include "Core/Game.hpp"

Game::Game() : window(sf::VideoMode({1064u, 800u}), "Flappy"), bg(textureManager, renderer), player(textureManager, renderer){


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
    player.update(deltaTime);
}

void Game::render() {
    window.clear();

    renderer.draw(window);

    window.display();
}