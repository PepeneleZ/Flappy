#pragma once

#include <SFML/Graphics.hpp>
#include "Collisions/CollisionEvent.hpp"
#include "Collisions/ICollidable.hpp"
#include "Events/EventDispatcher.hpp"

class ICollidable;
class CollisionManager {
    public:
        CollisionManager(EventDispatcher& dispatcher) : dispatcher(dispatcher) {};
        void checkCollisions();
        void addCollidable(ICollidable* collidable);

    private:
        EventDispatcher& dispatcher;
        std::vector<ICollidable*> objects;
};