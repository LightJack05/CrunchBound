#ifndef PLAYERBEHAVIOR_HPP
#define PLAYERBEHAVIOR_HPP

#include "../../../engine/components/behaviors/Behavior.hpp"

/**
 * @class PlayerBehavior
 * @brief The players basic behavior
 *
 */
class PlayerBehavior : public Behavior {
  protected:
    unsigned int jumpPoints = 0;
    const unsigned int defaultJumpPoints = 2;

  public:
    unsigned int getJumpPoints() const { return jumpPoints; };
    void setJumpPoints(unsigned int value) { jumpPoints = value; };
    /**
     * @brief Reset the players jump points to the default number.
     */
    void ResetJumpPoints();
    void OnTick() override;
    void OnStart() override;
};

#endif // PLAYERBEHAVIOR_HPP
