#include "Collisions/CollisionManager.hpp"

void CollisionManager::checkCollisions(){
    for (size_t i = 0; i < objects.size(); ++i) {
        for (size_t j = i + 1; j < objects.size(); ++j) {
            if(shouldCollide(objects[i], objects[j])){
                if (objects[i]->getBounds().findIntersection(objects[j]->getBounds()) && objects[i]->getType() != ObjectType::Ground && objects[i]->getType() != ObjectType::Pipes) {
                    dispatcher.dispatch(new CollisionEvent(objects[i], objects[j]));
                }
            }
        }
    }
}

bool CollisionManager::shouldCollide(ICollidable* objA, ICollidable* objB){
    if(objA->getCollisionCategory() == objB->getCollisionCategory()) return false; else return true;
}

void CollisionManager::addCollidable(ICollidable* obj) { objects.push_back(obj); }
void CollisionManager::removeCollidable(ICollidable* obj) { 
    for (auto it = objects.begin(); it != objects.end(); ) {
        if (*it == obj) { 
            it = objects.erase(it);
            break; 
        } else {
            ++it;
        }
    }
}

