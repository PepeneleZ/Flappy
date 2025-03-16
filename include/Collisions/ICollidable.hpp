#pragma once

#include <SFML/Graphics.hpp>
#include "Collisions/CollisionEvent.hpp"
#include "Collisions/CollisionManager.hpp"

enum class ObjectType {
    Player,
    Pipes,  
    Ground
};

enum class CollisionCategory {
    Player,
    Enviroment
};

class CollisionManager;
class ICollidable{
    public:

        virtual sf::FloatRect getBounds() const = 0;

        virtual void onCollision(Event* event) = 0;

        virtual ObjectType getType() const = 0;
        
        virtual CollisionCategory getCollisionCategory() const = 0;

        virtual bool isDestroyed() const = 0;

        virtual ~ICollidable() = default;

};