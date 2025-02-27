#include "CoffeeBehavior.hpp"
#include "../../../engine/ObjectManagement.hpp"

void CoffeeBehavior::OnTick() {
    // When the object goes off screen (with some margin), destroy it.
    if (this->parent->getPosition()->getX() < -200) {
        EnqueueDestroyGameObject(this->parent);
    }
}

void CoffeeBehavior::OnStart() {}
