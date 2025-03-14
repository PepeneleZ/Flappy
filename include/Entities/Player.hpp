# pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/Render.hpp"
#include "Graphics/TextureManager.hpp"

class Player{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock jumpTimer; 
        
        bool isJumping = false;
        float pull = 800.f;
        float jump = -250.f;
        float velocity = 0.f;

    public:
        Player(TextureManager&  textureManager, Render& render);
        void update(float deltaTime);
};