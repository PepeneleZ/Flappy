#include "Entities/Player.hpp"

#include <iostream>

Player::Player(TextureManager&  textureManager, Render& render) : texture(textureManager.getTexture("../../textures/sheet.png", sf::IntRect({110, 403}, {24, 18}))), sprite(texture){
    sprite.setOrigin({12.f, 9.f});
    sprite.setScale(sf::Vector2(4.f, 4.f));
    sprite.setPosition({532.f, 400.f});
    render.add(sprite, 2);
}

void Player::update(float deltaTime) {

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