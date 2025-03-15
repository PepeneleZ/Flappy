#include "Entities/Ground.hpp"
#include <iostream>

Ground::Ground(TextureManager&  tm, Render& render, CollisionManager& cm) 
    : texture(tm.getTexture("../../textures/sheet.png", sf::IntRect({0, 771}, {512, 168}), true))
    , sprite(texture)
    , ICollidable(cm)
{
    sprite.setTextureRect(sf::IntRect({0, 0}, {1024, 168}));
    sprite.setPosition({0.f, 600.f});
    render.add(sprite, 2);
}

sf::FloatRect Ground::getBounds() const {
    return sprite.getGlobalBounds();
}

void Ground::onCollision(Event* event) {
    
}

ObjectType Ground::getType() const {
    return ObjectType::Ground;
}

bool Ground::isDestroyed() const {
    return false;
}