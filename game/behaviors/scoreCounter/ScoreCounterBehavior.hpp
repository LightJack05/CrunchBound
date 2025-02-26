#ifndef SCORECOUNTERBEHAVIOR_HPP
#define SCORECOUNTERBEHAVIOR_HPP
#include "../../../engine/Time.hpp"
#include "../../../engine/components/behaviors/Behavior.hpp"

/**
 * @class ScoreCounterBehavior
 * @brief Controlls the behavior of the score counter
 *
 */
class ScoreCounterBehavior : public Behavior {
  protected:
    /**
     * @brief Get the player score at the current time.
     *
     * @return The current playerscore
     */
    long long GetPlayerScore() { return GetTimeSinceGameStart() / 1000; }

  public:
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // SCORECOUNTERBEHAVIOR_HPP
