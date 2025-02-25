#ifndef SCORECOUNTERBEHAVIOR_HPP
#define SCORECOUNTERBEHAVIOR_HPP
#include "../../../engine/components/behaviors/Behavior.hpp"

/**
 * @class ScoreCounterBehavior
 * @brief Controlls the behavior of the score counter
 *
 */
class ScoreCounterBehavior : public Behavior {
  public:
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // SCORECOUNTERBEHAVIOR_HPP
