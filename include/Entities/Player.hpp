# pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/Render.hpp"
#include "Graphics/TextureManager.hpp"
#include "Collisions/ICollidable.hpp"
#include "Events/EventDispatcher.hpp"

class Player : public ICollidable{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock jumpTimer; 
        
        bool isJumping = false;
        bool isCrashed = false;

        float pull = 800.f;
        float jump = -250.f;
        float velocity = 0.f;

    public:
        Player(TextureManager&  tm, Render& render, EventDispatcher& ed, CollisionManager& cm);
        void update(float deltaTime);
        void move(float deltaTime);

        sf::FloatRect getBounds() const override;
        void onCollision(Event* event) override;
        ObjectType getType() const override; 
        bool isDestroyed() const override;
};