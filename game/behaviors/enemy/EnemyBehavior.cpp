#include "EnemyBehavior.hpp"
#include "../../../engine/GameManagement.hpp"

void EnemyBehavior::OnTick() {
    if(this->parent->getPosition()->getX() < - 200){
        EnqueueDestroyGameObject(this->parent);
    }
}

void EnemyBehavior::OnStart() {}
