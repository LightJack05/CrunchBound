#ifndef COFFEEMETERBEHAVIOR_HPP
#define COFFEEMETERBEHAVIOR_HPP
#include "../../../engine/components/behaviors/Behavior.hpp"

class CoffeeMeterBehavior : public Behavior {
  protected:
    float coffeeLevel = 1000;

  public:
    float getCoffeeLevel() const { return coffeeLevel; }
    void setCoffeeLevel(float value) { coffeeLevel = value; }
    void IncreaseCoffeeLevel(float amount);
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // COFFEEMETERBEHAVIOR_HPP
