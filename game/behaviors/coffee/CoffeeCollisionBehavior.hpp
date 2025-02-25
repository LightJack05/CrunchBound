#ifndef COFFEECOLLISIONBEHAVIOR_HPP
#define COFFEECOLLISIONBEHAVIOR_HPP
#include "../../../engine/components/behaviors/CollisionBehavior.hpp"

/**
 * @class CoffeeCollisionBehavior
 * @brief Controlls the behavior of a coffee on collision
 * 
 */
class CoffeeCollisionBehavior : public CollisionBehavior {
  public:
    CoffeeCollisionBehavior();
    CoffeeCollisionBehavior(int x, int y);
    ~CoffeeCollisionBehavior();
    virtual void BeforeCollision(std::shared_ptr<GameObject> other) override;
};

#endif // COFFEECOLLISIONBEHAVIOR_HPP
