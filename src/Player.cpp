#include "Player.hpp"
#include "Draw.hpp"
#include <iostream>
Player::Player(const sf::Texture& texture, Draw& draw) : sprite(texture){
    draw.add(sprite, 2);
}

void Player::update() {
    // Move the player based on key input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        sprite.move({0.f, -5.f}); // Move up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        sprite.move({0.f, 5.f});   // Move down
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        sprite.move({-5.f, 0.f});  // Move left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        sprite.move({5.f, 0.f});   // Move right
    }
}