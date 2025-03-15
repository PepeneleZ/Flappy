#pragma once

#include <SFML/Graphics.hpp>
#include "Collisions/CollisionEvent.hpp"
#include "Collisions/CollisionManager.hpp"

enum class ObjectType {
    Player,
    Pipes,  
    Ground
};

class CollisionManager;
class ICollidable{
    public:
        ICollidable(CollisionManager& cm);

        virtual sf::FloatRect getBounds() const = 0;

        virtual void onCollision(Event* event) = 0;

        virtual ObjectType getType() const = 0;

        virtual bool isDestroyed() const = 0;

        virtual ~ICollidable() = default;

};