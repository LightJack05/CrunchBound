#include "CoffeeMeterBehavior.hpp"
#include "../../../engine/Time.hpp"
#include "../../../engine/components/renderers/RectangleRenderer.hpp"
#include "../../Lifecycle.hpp"

void CoffeeMeterBehavior::OnTick() {
    // Decrease the coffee meter every frame.
    coffeeLevel -= 0.02 * GetDeltaTime();
    // If the coffee meter reaches 0, the game is over.
    if (coffeeLevel <= 0) {
        GameOver();
    }
    // Scale and color the coffee meter according to the coffee level
    this->parent->getScale()->setX(coffeeLevel / 1000);
    this->parent->GetFirstComponent<RectangleRenderer>()->setColor(
        255 * (1 - (coffeeLevel / 1000)), 255 * (coffeeLevel / 1000), 0, 255);
}

void CoffeeMeterBehavior::OnStart() { coffeeLevel = 1000; }

void CoffeeMeterBehavior::IncreaseCoffeeLevel(float amount) {
    // Increase the coffee level by the amount, or set it to max, if the level would exceed 1000
    if (coffeeLevel + amount > 1000) {
        coffeeLevel = 1000;
    } else {
        coffeeLevel += amount;
    }
}
