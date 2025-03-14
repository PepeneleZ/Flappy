# pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/Render.hpp"
#include "Graphics/TextureManager.hpp"
#include "Entities/Ground.hpp"

class Background {
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        Ground ground;
    
    public:
        Background(TextureManager&  textureManager, Render& render);
};