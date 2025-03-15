#include "Entities/Player.hpp"

#include <iostream>

Player::Player(TextureManager&  tm, Render& render, EventDispatcher& ed, CollisionManager& cm) 
    : texture(tm.getTexture("../../textures/sheet.png"))
    , sprite(texture, sf::IntRect({689, 0}, {68, 48}))
    , ICollidable(cm)
{
    sprite.setOrigin({34.f, 24.f});
    sprite.setPosition({512.f, 384.f});

    ed.addListener(EventType::Collision, [&](Event* event) { onCollision(event); });

    render.add(sprite, 5);
}

void Player::update(float deltaTime) {
    if(!isCrashed) move(deltaTime);
}

void Player::move(float deltaTime){
    if (isJumping && jumpTimer.getElapsedTime().asMilliseconds() > 500.f) {
        isJumping = false;
    }

    velocity = velocity + pull * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
        sprite.setRotation(sf::degrees(330));
        velocity = jump; 
        isJumping = true;
        jumpTimer.restart();  
    }

    if(!isJumping && (sprite.getRotation() < sf::degrees(90) || sprite.getRotation() >= sf::degrees(330))){
        sprite.rotate(sf::degrees(1));
    }

    sprite.move({0.f, velocity * deltaTime});
}

sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}

void Player::onCollision(Event* event) {
    auto* collisionEvent = dynamic_cast<CollisionEvent*>(event);
    if (collisionEvent) {
        ICollidable* other = (collisionEvent->getObjectA() == this) ? collisionEvent->getObjectB() : collisionEvent->getObjectA();

        if (other->getType() == ObjectType::Ground) {
            isCrashed = true;
        }
    }
}

ObjectType Player::getType() const {
    return ObjectType::Player;
}

bool Player::isDestroyed() const {
    return false;
}