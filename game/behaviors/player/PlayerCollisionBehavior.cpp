#include "PlayerCollisionBehavior.hpp"
#include "../../../engine/components/behaviors/GravityBehavior.hpp"
#include "../../Lifecycle.hpp"
#include <memory>

void PlayerCollisionBehavior::BeforeCollision(
    std::shared_ptr<GameObject> other) {
    if (other->getTag() == "floor") {
        this->parent->setVelocity(std::make_shared<Vector2>(0, 0));
        this->parent->GetFirstComponent<GravityBehavior>()->setEnabled(false);
        this->parent->setPosition(std::make_shared<Vector2>(
            this->parent->getPosition()->getX(), other->getPosition()->getY() - this->parent->GetFirstComponent<CollisionBehavior>()->GetColliderSize()->getY()));
    }
    if (other->getTag() == "enemy") {
        GameOver();
    }
}

PlayerCollisionBehavior::PlayerCollisionBehavior() {}

PlayerCollisionBehavior::PlayerCollisionBehavior(int x, int y) {
    this->colliderSize->setX(x);
    this->colliderSize->setY(y);
}
