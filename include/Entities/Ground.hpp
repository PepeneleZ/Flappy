#pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/Render.hpp"
#include "Graphics/TextureManager.hpp"
#include "Collisions/ICollidable.hpp"

class Ground : public ICollidable{
    private:
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Ground(TextureManager&  tm, Render& render, CollisionManager& cm);

        sf::FloatRect getBounds() const override;
        void onCollision(Event* event) override;
        ObjectType getType() const override; 
        CollisionCategory getCollisionCategory() const override;
        bool isDestroyed() const override;
};  
