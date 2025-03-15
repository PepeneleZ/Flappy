#pragma once

#include "Graphics/Render.hpp"
#include "Graphics/TextureManager.hpp"
#include "Entities/Player.hpp"
#include "Entities/Background.hpp"
#include "Entities/Ground.hpp"
#include "Collisions/CollisionManager.hpp"
#include "Events/EventDispatcher.hpp"
#include <vector>

class ICollidables;
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
        EventDispatcher eventDispatcher;
        CollisionManager collisionManager;

        Background bg;
        Player player;
        Ground ground;

};