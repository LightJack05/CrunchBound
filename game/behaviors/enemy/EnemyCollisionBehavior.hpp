#ifndef ENEMYCOLLISIONBEHAVIOR_HPP
#define ENEMYCOLLISIONBEHAVIOR_HPP

#include "../../../engine/components/behaviors/CollisionBehavior.hpp"

/**
 * @class EnemyCollisionBehavior
 * @brief Controlls the behavior of an enemy on collision
 *
 */
class EnemyCollisionBehavior : public CollisionBehavior {
  public:
    EnemyCollisionBehavior();
    EnemyCollisionBehavior(int x, int y);
    virtual void BeforeCollision(std::shared_ptr<GameObject> other) override;
};

#endif // ENEMYCOLLISIONBEHAVIOR_HPP
