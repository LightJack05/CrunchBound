#ifndef PLAYERBEHAVIOR_HPP
#define PLAYERBEHAVIOR_HPP

#include "../../../engine/components/behaviors/Behavior.hpp"

/**
 * @class PlayerBehavior
 * @brief The players basic behavior
 *
 */
class PlayerBehavior : public Behavior {
  public:
    void OnTick() override;
    void OnStart() override;
};

#endif // PLAYERBEHAVIOR_HPP
