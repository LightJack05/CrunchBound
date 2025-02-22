#include "PlayerCollisionBehavior.hpp"
#include "../../../engine/components/behaviors/GravityBehavior.hpp"
#include "../../Lifecycle.hpp"
#include "PlayerBehavior.hpp"
#include <memory>

void PlayerCollisionBehavior::BeforeCollision(
    std::shared_ptr<GameObject> other) {
    if (other->getTag() == "floor") {
        this->parent->getVelocity()->setY(0);
        this->parent->GetFirstComponent<GravityBehavior>()->setEnabled(false);
        this->parent->setPosition(std::make_shared<Vector2>(
            this->parent->getPosition()->getX(),
            other->getPosition()->getY() -
                (this->parent->GetFirstComponent<CollisionBehavior>()
                     ->getColliderSize()
                     ->getY() *
                 this->parent->getScale()->getY())));
        this->parent->GetFirstComponent<PlayerBehavior>()->ResetJumpPoints();
    }
    if (other->getTag() == "enemy") {
        GameOver();
    }
    if (other->getTag() == "right-wall") {
        this->parent->getVelocity()->setX(0);
    }
    if (other->getTag() == "left-wall") {
        this->parent->getVelocity()->setX(0);
    }
}

PlayerCollisionBehavior::PlayerCollisionBehavior() {}

PlayerCollisionBehavior::PlayerCollisionBehavior(int x, int y) {
    this->colliderSize->setX(x);
    this->colliderSize->setY(y);
}
