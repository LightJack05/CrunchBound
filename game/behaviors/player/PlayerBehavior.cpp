#include "PlayerBehavior.hpp"


void PlayerBehavior::OnStart() {}
void PlayerBehavior::OnTick() {}
void PlayerBehavior::ResetJumpPoints() {
    this->jumpPoints = defaultJumpPoints;
}
