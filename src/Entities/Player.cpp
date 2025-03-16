#include "Entities/Player.hpp"

#include <iostream>

Player::Player(TextureManager&  tm, Render& render, EventDispatcher& ed, CollisionManager& cm) 
    : texture(tm.getTexture("../../textures/sheet.png"))
    , sprite(texture, sf::IntRect({689, 0}, {68, 48}))
{
    sprite.setOrigin({34.f, 24.f});
    sprite.setPosition({512.f, 300.f});

    collisionBox = sf::FloatRect(sf::Vector2(sprite.getPosition().x - sprite.getTextureRect().size.x / 2, sprite.getPosition().y + sprite.getTextureRect().size.y / 2), sf::Vector2(68.f, 48.f));

    /*collisionShape.setSize(collisionBox.size);
    collisionShape.setPosition(collisionBox.position);
    collisionShape.setFillColor(sf::Color::Transparent); 
    collisionShape.setOutlineThickness(1);
    collisionShape.setOutlineColor(sf::Color::Red);
    render.add(collisionShape, 10);*/

    cm.addCollidable(this);
    ed.addListener(EventType::Collision, [&](Event* event) { onCollision(event); });

    render.add(sprite, 5);
}

void Player::update(float deltaTime) {
    collisionBox.position.x = sprite.getPosition().x - sprite.getTextureRect().size.x / 2;
    collisionBox.position.y = sprite.getPosition().y - sprite.getTextureRect().size.y / 2;
    //collisionShape.setPosition(collisionBox.position);
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
    return collisionBox;
}

void Player::onCollision(Event* event) {
    auto* collisionEvent = dynamic_cast<CollisionEvent*>(event);
    if (collisionEvent) {
        ICollidable* other = (collisionEvent->getObjectA() == this) ? collisionEvent->getObjectB() : collisionEvent->getObjectA();

        if (other->getType() == ObjectType::Ground || other->getType() == ObjectType::Pipes) std::cout << "beu";
    }
}

ObjectType Player::getType() const {
    return ObjectType::Player;
}

CollisionCategory Player::getCollisionCategory() const {
    return CollisionCategory::Player;
}

bool Player::isDestroyed() const {
    return false;
}