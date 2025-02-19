#ifndef GAMEMANAGERBEHAVIOR_HPP
#define GAMEMANAGERBEHAVIOR_HPP

#include "../../../engine/components/behaviors/Behavior.hpp"

class GameManagerBehavior : public Behavior {
  public:
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // GAMEMANAGERBEHAVIOR_HPP
