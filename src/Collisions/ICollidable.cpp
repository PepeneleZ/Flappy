#include "Collisions/ICollidable.hpp"

ICollidable::ICollidable(CollisionManager& cm) {
    cm.addCollidable(this); 
}