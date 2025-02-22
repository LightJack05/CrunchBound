#include "CoffeeMeterBehavior.hpp"
#include "../../../engine/Time.hpp"
#include "../../Lifecycle.hpp"

static float CoffeeLevel = 1000;

void CoffeeMeterBehavior::OnTick() {
    CoffeeLevel -= 0.02 * GetDeltaTime();
    if (CoffeeLevel <= 0) {
        GameOver();
    }
    this->parent->getScale()->setX(CoffeeLevel / 1000);
}

void CoffeeMeterBehavior::OnStart() { CoffeeLevel = 1000; }
