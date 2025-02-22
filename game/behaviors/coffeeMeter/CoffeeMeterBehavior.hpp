#ifndef COFFEEMETERBEHAVIOR_HPP
#define COFFEEMETERBEHAVIOR_HPP
#include "../../../engine/components/behaviors/Behavior.hpp"

class CoffeeMeterBehavior : public Behavior {
  public:
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // COFFEEMETERBEHAVIOR_HPP
