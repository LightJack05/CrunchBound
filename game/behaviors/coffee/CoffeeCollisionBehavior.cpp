#include "CoffeeCollisionBehavior.hpp"
#include "../../../engine/ObjectManagement.hpp"
#include "../coffeeMeter/CoffeeMeterBehavior.hpp"
#include <memory>

void CoffeeCollisionBehavior::BeforeCollision(
    // On collsion with the player, increase their coffee level, and destroy
    // this object
    std::shared_ptr<GameObject> other) {
    if (other->getTag() == "player") {
        GetGameObjectByTag("coffee-meter")
            ->GetFirstComponent<CoffeeMeterBehavior>()
            ->IncreaseCoffeeLevel(350);
        EnqueueDestroyGameObject(this->parent);
    }
}

CoffeeCollisionBehavior::CoffeeCollisionBehavior() {}

CoffeeCollisionBehavior::CoffeeCollisionBehavior(int x, int y) {
    this->colliderSize->setX(x);
    this->colliderSize->setY(y);
}

CoffeeCollisionBehavior::~CoffeeCollisionBehavior() {}
