#include "Entities/Ground.hpp"

Ground::Ground(TextureManager&  textureManager) : texture(textureManager.getTexture("../../textures/sheet.png", sf::IntRect({291, 0}, {168, 56}))), sprite(texture){
    sprite.setScale(sf::Vector2(6.5f, 3.f));
    sprite.setOrigin({84.f, 28.f});
    sprite.setPosition({532.f, 744.f});
}

void Ground::draw(Render& render){
    render.add(sprite, 1);
}