#pragma once

#include "Graphics/Render.hpp"
#include "Graphics/TextureManager.hpp"
#include "Entities/Player.hpp"
#include "Entities/Background.hpp"
#include "Entities/Ground.hpp"
#include "Entities/Pipes/PipePair.hpp"
#include "Collisions/CollisionManager.hpp"
#include "Events/EventDispatcher.hpp"
#include <list>

class ICollidables;
class Game{
    public:
        Game();
        //~Game();
        
        void run();

    private:
        void update(float deltaTime);
        void render();
        void spawnPipes(float deltaTime);

        sf::RenderWindow window;
        sf::Clock clock;
        sf::Clock pipesClock;

        Render renderer;
        TextureManager tm;
        EventDispatcher ed;
        CollisionManager cm;

        Background bg;
        Player player;
        Ground ground;

        std::list<PipePair> pipes;
        float timeSinceLastPipe = 0.f;
        float spawnPipeInterval = 1.5f;
        float startX = 1200;

};