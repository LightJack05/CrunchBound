#include "EnemyCollisionBehavior.hpp"
#include "../../../engine/components/behaviors/GravityBehavior.hpp"
#include <iostream>
#include <memory>

void EnemyCollisionBehavior::BeforeCollision(
    std::shared_ptr<GameObject> other) {
    if (other->getTag() == "player") {
        std::cout << "He's dead Jim." << std::endl;
    }
}

EnemyCollisionBehavior::EnemyCollisionBehavior() {}

EnemyCollisionBehavior::EnemyCollisionBehavior(int x, int y) {
    this->colliderSize->setX(x);
    this->colliderSize->setY(y);
}
