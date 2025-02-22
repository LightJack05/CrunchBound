#include "CoffeeMeterBehavior.hpp"
#include "../../../engine/Time.hpp"
#include "../../Lifecycle.hpp"

void CoffeeMeterBehavior::OnTick() {
    coffeeLevel -= 0.02 * GetDeltaTime();
    if (coffeeLevel <= 0) {
        GameOver();
    }
    this->parent->getScale()->setX(coffeeLevel / 1000);
}

void CoffeeMeterBehavior::OnStart() { coffeeLevel = 1000; }

void CoffeeMeterBehavior::IncreaseCoffeeLevel(float amount) {
    if (coffeeLevel + amount > 1000) {
        coffeeLevel = 1000;
    } else {
        coffeeLevel += amount;
    }
}
