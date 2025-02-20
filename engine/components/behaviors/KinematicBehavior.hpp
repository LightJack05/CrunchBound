#ifndef KINEMATICBEHAVIOR_HPP
#define KINEMATICBEHAVIOR_HPP

#include "Behavior.hpp"
/**
 * @class KinematicBehavior
 * @brief Component causing the velocity of an object to update it's position.
 *
 */
class KinematicBehavior : public Behavior {
  public:
    void OnTick() override;
    void OnStart() override;
};

#endif // KINEMATICBEHAVIOR_HPP
