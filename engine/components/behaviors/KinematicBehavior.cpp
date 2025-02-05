#include "KinematicBehavior.hpp"
#include "../../Time.hpp"

void KinematicBehavior::OnTick() {
    parent->getPosition()->setX(
        this->parent->getPosition()->getX() +
        (this->parent->getVelocity()->getX() * GetDeltaTime()));
    parent->getPosition()->setY(
        this->parent->getPosition()->getY() +
        (this->parent->getVelocity()->getY() * GetDeltaTime()));
}

void KinematicBehavior::OnStart() {}
