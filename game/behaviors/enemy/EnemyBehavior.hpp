#ifndef ENEMYBEHAVIOR_HPP
#define ENEMYBEHAVIOR_HPP

#include "../../../engine/components/behaviors/Behavior.hpp"

/**
 * @class EnemyBehavior
 * @brief Controlls the behavior of an Enemy.
 *
 */
class EnemyBehavior : public Behavior {
  public:
    void OnTick() override;
    void OnStart() override;
};

#endif // ENEMYBEHAVIOR_HPP
