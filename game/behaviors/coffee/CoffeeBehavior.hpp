#ifndef COFFEEBEHAVIOR_HPP
#define COFFEEBEHAVIOR_HPP
#include "../../../engine/components/behaviors/Behavior.hpp"

class CoffeeBehavior : public Behavior {
  public:
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // COFFEEBEHAVIOR_HPP
