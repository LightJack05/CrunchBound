#ifndef GRAVITYBEHAVIOR_HPP
#define GRAVITYBEHAVIOR_HPP

#include "Behavior.hpp"
/**
 * @class GravityBehavior
 * @brief Component that gives an object gravity
 *
 */
class GravityBehavior : public Behavior {
  protected:
    /**
     * @brief The scale of the gravity applied, linear
     */
    float gravityScale = 1;

  public:
    float getGravityScale() { return gravityScale; }
    void setGravityScale(float value) { gravityScale = value; }
    void OnTick() override;
    void OnStart() override;
};

#endif // GRAVITYBEHAVIOR_HPP
