#include "CoffeeBehavior.hpp"
#include "../../../engine/GameManagement.hpp"

void CoffeeBehavior::OnTick() {
    if (this->parent->getPosition()->getX() < -200) {
        EnqueueDestroyGameObject(this->parent);
    }
}

void CoffeeBehavior::OnStart() {}
