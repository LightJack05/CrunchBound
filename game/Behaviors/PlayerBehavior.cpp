#include "PlayerBehavior.hpp"
#include <iostream>

void PlayerBehavior::OnStart() {}
void PlayerBehavior::OnTick() {
    std::cout << this->parent->getPosition()->getY() << std::endl;
}
