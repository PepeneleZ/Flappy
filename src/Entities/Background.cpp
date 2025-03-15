#include "Entities/Background.hpp"
#include <iostream>

Background::Background(TextureManager&  textureManager, Render& render) 
    : texture(textureManager.getTexture("../../textures/sheet.png"
        ,  sf::IntRect({0, 0}, {342, 768}), true)), sprite(texture)     
{
    sprite.setTextureRect(sf::IntRect({0, 0}, {1024, 768}));
    render.add(sprite, 1);
}