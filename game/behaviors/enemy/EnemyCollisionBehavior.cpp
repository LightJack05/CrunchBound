#include "EnemyCollisionBehavior.hpp"
#include "../../Lifecycle.hpp"
#include <memory>

void EnemyCollisionBehavior::BeforeCollision(
    std::shared_ptr<GameObject> other) {
    // On collision with a player, the game is over.
    if (other->getTag() == "player") {
        GameOver();
    }
}

EnemyCollisionBehavior::EnemyCollisionBehavior() {}

EnemyCollisionBehavior::EnemyCollisionBehavior(int x, int y) {
    this->colliderSize->setX(x);
    this->colliderSize->setY(y);
}
