#include "EnemyCollisionBehavior.hpp"
#include "../../Lifecycle.hpp"
#include <memory>

void EnemyCollisionBehavior::BeforeCollision(
    std::shared_ptr<GameObject> other) {
    if (other->getTag() == "player") {
        GameOver();
    }
}

EnemyCollisionBehavior::EnemyCollisionBehavior() {}

EnemyCollisionBehavior::EnemyCollisionBehavior(int x, int y) {
    this->colliderSize->setX(x);
    this->colliderSize->setY(y);
}
