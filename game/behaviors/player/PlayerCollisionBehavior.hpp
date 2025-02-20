#ifndef PLAYERCOLLISIONBEHAVIOR_HPP
#define PLAYERCOLLISIONBEHAVIOR_HPP

#include "../../../engine/components/behaviors/CollisionBehavior.hpp"

/**
 * @class PlayerCollisionBehavior
 * @brief The players collision behavior.
 *
 */
class PlayerCollisionBehavior : public CollisionBehavior {
  public:
    PlayerCollisionBehavior();
    PlayerCollisionBehavior(int x, int y);
    virtual void BeforeCollision(std::shared_ptr<GameObject> other) override;
};

#endif // PLAYERCOLLISIONBEHAVIOR_HPP
