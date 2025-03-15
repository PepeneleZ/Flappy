#include "Collisions/CollisionEvent.hpp"

CollisionEvent::CollisionEvent(ICollidable* a, ICollidable* b) : objectA(a), objectB(b) {

}

EventType CollisionEvent::getType() const {
    return EventType::Collision;
}

ICollidable* CollisionEvent::getObjectA() const { return objectA; }
ICollidable* CollisionEvent::getObjectB() const { return objectB; }