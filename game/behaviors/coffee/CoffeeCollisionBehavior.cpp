#include "CoffeeCollisionBehavior.hpp"
#include "../../../engine/GameManagement.hpp"
#include "../../Lifecycle.hpp"
#include "../coffeeMeter/CoffeeMeterBehavior.hpp"
#include <memory>

void CoffeeCollisionBehavior::BeforeCollision(
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
