#include "Entities/Pipes/PipePair.hpp"

PipePair::PipePair(TextureManager& tm, Render& render, EventDispatcher& ed, CollisionManager& cm, float startX)
    : topPipe(tm, render, ed, cm), bottomPipe(tm, render, ed, cm) {

    float randomOffset = rand() % 70 - 30; 
    float randomHeight = rand() % 200 + 100;

    topPipe.sprite.setPosition(sf::Vector2(startX, 0 + randomHeight));
    topPipe.collisionBox.position = sf::Vector2(topPipe.collisionBox.size.x, -topPipe.collisionBox.size.y + topPipe.sprite.getPosition().y);

    bottomPipe.sprite.setPosition(sf::Vector2(startX, topPipe.sprite.getPosition().y + gapSize + randomOffset));
    bottomPipe.collisionBox.position = sf::Vector2(bottomPipe.collisionBox.size.x, topPipe.sprite.getPosition().y + gapSize + randomOffset);
    bottomPipe.sprite.setScale(sf::Vector2(1.f, -1.f));
}

void PipePair::update(float deltaTime) {
    topPipe.update(deltaTime);
    bottomPipe.update(deltaTime);
}

bool PipePair::isOffScreen() const {
    return topPipe.sprite.getPosition().x + bottomPipe.sprite.getPosition().x < -200;
}

float PipePair::getX() const {
    return topPipe.sprite.getPosition().x;
}

void PipePair::clean(Render& render, CollisionManager& cm){
    topPipe.clean(render, cm);
    bottomPipe.clean(render, cm);
}