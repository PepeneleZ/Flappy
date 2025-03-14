#pragma once

#include "Graphics/Render.hpp"
#include "Graphics/TextureManager.hpp"
#include "Entities/Player.hpp"
#include "Entities/Background.hpp"

class Game{
    public:
        Game();
        //~Game();
        
        void run();

    private:
        void update(float deltaTime);
        void render();

        sf::RenderWindow window;
        sf::Clock clock;
        Render renderer;
        TextureManager textureManager;

        Background bg;
        Player player;
};