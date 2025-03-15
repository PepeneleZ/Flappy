#include "Collisions/CollisionManager.hpp"

void CollisionManager::checkCollisions(){
    for (size_t i = 0; i < objects.size(); ++i) {
        for (size_t j = i + 1; j < objects.size(); ++j) {
            if (objects[i]->getBounds().findIntersection(objects[j]->getBounds())) {
                dispatcher.dispatch(new CollisionEvent(objects[i], objects[j]));
            }
        }
    }
}

void CollisionManager::addCollidable(ICollidable* obj) { objects.push_back(obj); }

