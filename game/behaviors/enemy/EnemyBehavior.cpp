#include "EnemyBehavior.hpp"
#include "../../../engine/ObjectManagement.hpp"

void EnemyBehavior::OnTick() {
    // If the object is off screen, destroy it.
    if(this->parent->getPosition()->getX() < - 200){
        EnqueueDestroyGameObject(this->parent);
    }
}

void EnemyBehavior::OnStart() {}
