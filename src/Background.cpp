#include "Background.hpp"

Background::Background(const sf::Texture& texture, Draw& draw) : sprite(texture){
    draw.add(sprite, 1);
}