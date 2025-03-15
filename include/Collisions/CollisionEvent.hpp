#pragma once

#include "Events/Event.hpp"
#include "Collisions/ICollidable.hpp"

class ICollidable;
class CollisionEvent : public Event {
    public:
        CollisionEvent(ICollidable* a, ICollidable* b);

        EventType getType() const;

        ICollidable* getObjectA() const;
        ICollidable* getObjectB() const;
        
    private:
        ICollidable* objectA;
        ICollidable* objectB;
};