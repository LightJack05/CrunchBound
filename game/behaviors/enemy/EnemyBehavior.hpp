#ifndef ENEMYBEHAVIOR_HPP
#define ENEMYBEHAVIOR_HPP

#include "../../../engine/components/behaviors/Behavior.hpp"

class EnemyBehavior : public Behavior {
  public:
    void OnTick() override;
    void OnStart() override;
};

#endif // ENEMYBEHAVIOR_HPP
