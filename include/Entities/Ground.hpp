#pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/Render.hpp"
#include "Graphics/TextureManager.hpp"

class Ground {
    private:
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Ground(TextureManager&  textureManager);
        void draw(Render& render);
};  
