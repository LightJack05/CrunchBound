#include "GravityBehavior.hpp"
#include "../../Time.hpp"

void GravityBehavior::OnTick() {
    this->parent->getVelocity()->setY(this->parent->getVelocity()->getY() +
                                      (0.005 * gravityScale) * GetDeltaTime());
}

void GravityBehavior::OnStart() {}
