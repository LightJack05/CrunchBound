#include "GravityBehavior.hpp"
#include "../../Time.hpp"

void GravityBehavior::OnTick() {
    // Increase the y velocity of the object by a fixed number depending on DeltaTime and gravity scale
    this->parent->getVelocity()->setY(this->parent->getVelocity()->getY() +
                                      (0.005 * gravityScale) * GetDeltaTime());
}

void GravityBehavior::OnStart() {}
