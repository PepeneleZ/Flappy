# pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/Render.hpp"
#include "Collisions/ICollidable.hpp"
#include "Graphics/TextureManager.hpp"

class Pipe : public ICollidable {
    public:
        Pipe(TextureManager&  tm, Render& render, EventDispatcher& ed, CollisionManager& cm);
        void update(float deltaTime);
        void move(float deltaTime);

        sf::FloatRect getBounds() const override;
        void onCollision(Event* event) override;
        ObjectType getType() const override; 
        CollisionCategory getCollisionCategory() const override;
        bool isDestroyed() const override;

        sf::Texture texture;
        sf::Sprite sprite;
        sf::FloatRect collisionBox;
        sf::RectangleShape collisionShape;

        float gap = 760.f;
        float velocity;
        float speed = 160.f;
}; 