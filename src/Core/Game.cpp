#include "Core/Game.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode({1024u, 768u}), "Flappy") 
    , bg(tm, renderer)
    , ground(tm, renderer, cm)
    , player(tm, renderer, ed, cm)
    , cm(ed)
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

    cm.checkCollisions();

    if(!player.isDead()){
        spawnPipes(deltaTime);
    }

    player.update(deltaTime);
    
}

void Game::spawnPipes(float deltaTime){

    timeSinceLastPipe = pipesClock.getElapsedTime().asSeconds();

    if (timeSinceLastPipe >= spawnPipeInterval) {
        pipes.emplace_back(tm, renderer, ed, cm, startX);
        pipesClock.restart(); 
    }

    for (auto it = pipes.begin(); it != pipes.end(); ) {
        if (it->isOffScreen()) {
            it->clean(renderer, cm);
            it = pipes.erase(it); 
        } else {
            it->update(deltaTime);
            ++it;
        }
    }


}

void Game::render() {
    window.clear();

    renderer.draw(window);

    window.display();
}