#include "PlayerCollisionBehavior.hpp"
#include "../../engine/components/behaviors/GravityBehavior.hpp"
#include <iostream>
#include <memory>
#include <ostream>

void PlayerCollisionBehavior::BeforeCollision(
    std::shared_ptr<GameObject> other) {
    if(other->getTag() == "floor"){
        this->parent->GetFirstComponent<GravityBehavior>()->setEnabled(false);
    }
}

PlayerCollisionBehavior::PlayerCollisionBehavior() {}

PlayerCollisionBehavior::PlayerCollisionBehavior(int x, int y) {
    this->colliderSize->setX(x);
    this->colliderSize->setY(y);
}
