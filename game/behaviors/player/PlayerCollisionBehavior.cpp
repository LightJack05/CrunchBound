#include "PlayerCollisionBehavior.hpp"
#include "../../../engine/ObjectManagement.hpp"
#include "../../../engine/components/behaviors/GravityBehavior.hpp"
#include "../../Lifecycle.hpp"
#include "../coffeeMeter/CoffeeMeterBehavior.hpp"
#include "PlayerBehavior.hpp"
#include <memory>

void PlayerCollisionBehavior::BeforeCollision(
    std::shared_ptr<GameObject> other) {
    // When colliding with the floor...
    if (other->getTag() == "floor") {
        // ... set the velocity to 0 ...
        this->parent->getVelocity()->setY(0);

        // ... disable the gravity behavior ...
        this->parent->GetFirstComponent<GravityBehavior>()->setEnabled(false);

        // ... set the players position to be standing on the floor ...
        this->parent->setPosition(std::make_shared<Vector2>(
            this->parent->getPosition()->getX(),
            other->getPosition()->getY() -
                (this->parent->GetFirstComponent<CollisionBehavior>()
                     ->getColliderSize()
                     ->getY() *
                 this->parent->getScale()->getY())));

        // ... and reset their jump points.
        this->parent->GetFirstComponent<PlayerBehavior>()->ResetJumpPoints();
    }
    // On collision with an enemy, reset the game
    if (other->getTag() == "enemy") {
        GameOver();
    }
    // On collision with a coffee, increase the coffee level, and destroy the
    // coffee
    if (other->getTag() == "coffee") {
        GetGameObjectByTag("coffee-meter")
            ->GetFirstComponent<CoffeeMeterBehavior>()
            ->IncreaseCoffeeLevel(350);
        EnqueueDestroyGameObject(other.get());
    }
    // Disallow moving beyond the left and right wall.
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
