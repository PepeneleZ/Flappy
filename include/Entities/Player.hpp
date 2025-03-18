# pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/Render.hpp"
#include "Graphics/TextureManager.hpp"
#include "Collisions/ICollidable.hpp"
#include "Events/EventDispatcher.hpp"

class Player : public ICollidable{
    public:
        Player(TextureManager&  tm, Render& render, EventDispatcher& ed, CollisionManager& cm);
        void update(float deltaTime);
        bool isDead();

    private:
        sf::Texture texture;
        sf::Sprite sprite;

        sf::FloatRect collisionBox;
        sf::RectangleShape collisionShape;
        
        void updateCollisionBox();
        bool showCollisionBox = true;

        void move(float deltaTime);
        sf::Clock jumpTimer; 
        bool isJumping = false;
        bool isCrashing = false;
        bool isCrashed = false;
        float pull = 1500.f;
        float jump = -270.f;
        float velocity = 0.f;

        void animate();
        sf::Clock animationTimer;
        const int frameWidth = 68; 
        const int frameHeight = 48;
        const int numFrames = 3;   
        int currentFrame = 0;
        float frameTime = 0.13f;

        sf::FloatRect getBounds() const override;
        void onCollision(Event* event) override;
        ObjectType getType() const override; 
        CollisionCategory getCollisionCategory() const override;
        bool isDestroyed() const override;

};