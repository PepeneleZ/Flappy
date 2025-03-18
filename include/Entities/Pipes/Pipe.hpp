# pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/Render.hpp"
#include "Collisions/ICollidable.hpp"
#include "Graphics/TextureManager.hpp"

class Pipe : public ICollidable {
    public:
        Pipe(TextureManager&  tm, Render& render, EventDispatcher& ed, CollisionManager& cm);
        void update(float deltaTime);
        void clean(Render& render, CollisionManager& cm);

        sf::Texture texture;
        sf::Sprite sprite;
        sf::FloatRect collisionBox;
        sf::RectangleShape collisionShape;

    private:

        void updateCollisionBox();
        void move(float deltaTime);

        float gap = 760.f;
        float velocity;
        float speed = 200.f;

        bool showCollisionBox = true;

        sf::FloatRect getBounds() const override;
        void onCollision(Event* event) override;
        ObjectType getType() const override; 
        CollisionCategory getCollisionCategory() const override;
        bool isDestroyed() const override;
    
}; 