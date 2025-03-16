#include "Entities/Pipes/PipePair.hpp"\

PipePair::PipePair(TextureManager& tm, Render& render, EventDispatcher& ed, CollisionManager& cm)
    : topPipe(tm, render, ed, cm), bottomPipe(tm, render, ed, cm) {

    float randomOffset = rand() % 250 - 125; 

    topPipe.sprite.setPosition(sf::Vector2(1000.f, 200.f));
    topPipe.collisionBox.position = sf::Vector2(topPipe.collisionBox.size.x, -topPipe.collisionBox.size.y + topPipe.sprite.getPosition().y);

    bottomPipe.sprite.setPosition(sf::Vector2(1000.f, topPipe.sprite.getPosition().y + gapSize + randomOffset));
    bottomPipe.collisionBox.position = sf::Vector2(bottomPipe.collisionBox.size.x, topPipe.sprite.getPosition().y + gapSize + randomOffset);
    bottomPipe.sprite.setScale(sf::Vector2(1.f, -1.f));
}

void PipePair::update(float deltaTime) {
    topPipe.update(deltaTime);
    bottomPipe.update(deltaTime);
}

bool PipePair::isOffScreen() const {
    return topPipe.sprite.getPosition().x + topPipe.sprite.getPosition().x < 0;
}

float PipePair::getX() const {
    return topPipe.sprite.getPosition().x;
}