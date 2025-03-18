#include "Entities/Player.hpp"

#include <iostream>

Player::Player(TextureManager&  tm, Render& render, EventDispatcher& ed, CollisionManager& cm) 
    : texture(tm.getTexture("../../textures/sheet.png"))
    , sprite(texture, sf::IntRect({689, 0}, {68, 48}))
{
    sprite.setOrigin({34.f, 24.f});
    sprite.setPosition({512.f, 300.f});

    collisionBox = sf::FloatRect(sf::Vector2(sprite.getPosition().x - sprite.getTextureRect().size.x / 2, sprite.getPosition().y + sprite.getTextureRect().size.y / 2), sf::Vector2(68.f, 48.f));

    cm.addCollidable(this);
    ed.addListener(EventType::Collision, [&](Event* event) { onCollision(event); });

    render.add(sprite, 5);

    if(showCollisionBox){
        collisionShape.setSize(collisionBox.size);
        collisionShape.setPosition(collisionBox.position);
        collisionShape.setFillColor(sf::Color::Transparent); 
        collisionShape.setOutlineThickness(1);
        collisionShape.setOutlineColor(sf::Color::Red);
        render.add(collisionShape, 10);
    }
}

void Player::update(float deltaTime) {
    if(!isCrashed) move(deltaTime);
    updateCollisionBox();
    if(!isCrashed) animate();
}

void Player::updateCollisionBox(){
    collisionBox.position.x = sprite.getPosition().x - sprite.getTextureRect().size.x / 2;
    collisionBox.position.y = sprite.getPosition().y - sprite.getTextureRect().size.y / 2;
    if(showCollisionBox) collisionShape.setPosition(collisionBox.position);
}

void Player::move(float deltaTime){
    if (isJumping && jumpTimer.getElapsedTime().asMilliseconds() > 550.f) {
        isJumping = false;
    }

    velocity = velocity + pull * deltaTime;

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) && !isCrashing) {
        sprite.setRotation(sf::degrees(340));
        velocity = jump; 
        isJumping = true;
        jumpTimer.restart();  
    }

    if(!isJumping && (sprite.getRotation() < sf::degrees(90) || sprite.getRotation() >= sf::degrees(330))){
        sprite.rotate(sf::degrees(1));
    }

    sprite.move({0.f, velocity * deltaTime});
}

void Player::animate(){
    if(animationTimer.getElapsedTime().asSeconds() > frameTime){
        currentFrame = (currentFrame + 1) % numFrames;
        sprite.setTextureRect(sf::IntRect({689 + currentFrame * frameWidth + 3 * currentFrame, 0}, {frameWidth, frameHeight}));
        animationTimer.restart();
    }
}

bool Player::isDead(){
    return isCrashed || isCrashing;
}



sf::FloatRect Player::getBounds() const {
    return collisionBox;
}

void Player::onCollision(Event* event) {
    auto* collisionEvent = dynamic_cast<CollisionEvent*>(event);
    if (collisionEvent) {
        ICollidable* other = (collisionEvent->getObjectA() == this) ? collisionEvent->getObjectB() : collisionEvent->getObjectA();

        if (other->getType() == ObjectType::Ground) isCrashed = true;
        if (other->getType() == ObjectType::Pipes) isCrashing = true;
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