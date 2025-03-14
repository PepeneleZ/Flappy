#include "Entities/Background.hpp"

Background::Background(TextureManager&  textureManager, Render& render) 
: texture(textureManager.getTexture("../../textures/background.png")), sprite(texture), ground(textureManager){
    render.add(sprite, 1);
    ground.draw(render);
}