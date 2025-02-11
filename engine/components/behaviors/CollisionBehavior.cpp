#include "CollisionBehavior.hpp"
#include "../../GameManagement.hpp"
#include "../../Time.hpp"
#include <cstdio>
#include <iostream>
#include <memory>
#include <ostream>

CollisionBehavior::CollisionBehavior() {}

CollisionBehavior::CollisionBehavior(int x, int y) {
    this->colliderSize->setX(x);
    this->colliderSize->setY(y);
}

void CollisionBehavior::OnTick() {
    for (const std::shared_ptr<GameObject> other : gameObjects) {
        if (other.get() == this->parent) {
            continue;
        }
        if (CheckForCollision(other)) {
            this->BeforeCollision(other);
        }
    }
}

bool CollisionBehavior::CheckForCollision(std::shared_ptr<GameObject> other) {
    std::shared_ptr<CollisionBehavior> collider;
    try {
        collider = other->GetFirstComponent<CollisionBehavior>();
    } catch (ComponentNotFoundException) {
        return false;
    }

    Vector2 parentOrigin = *this->parent->getPosition();
    Vector2 parentVelocity = *this->parent->getVelocity();
    float positionChangeX = parent->getVelocity()->getX() * GetDeltaTime();
    float positionChangeY = parent->getVelocity()->getY() * GetDeltaTime();

    Vector2 thisCornerTL = Vector2(parentOrigin.getX() + positionChangeX,
                                   parentOrigin.getY() + positionChangeY);
    Vector2 thisCornerTR = Vector2(
        parentOrigin.getX() + this->colliderSize->getX() + positionChangeX,
        parentOrigin.getY() + positionChangeY);
    Vector2 thisCornerBL = Vector2(
        parentOrigin.getX() + positionChangeX,
        parentOrigin.getY() + this->colliderSize->getY() + positionChangeY);
    Vector2 thisCornerBR = Vector2(
        parentOrigin.getX() + this->colliderSize->getX() + positionChangeX,
        parentOrigin.getY() + this->colliderSize->getY() + positionChangeY);

    bool collision = false;

    collision = collision ?: collider->IsPointInsideCollider(thisCornerTL);
    collision = collision ?: collider->IsPointInsideCollider(thisCornerBL);
    collision = collision ?: collider->IsPointInsideCollider(thisCornerTR);
    collision = collision ?: collider->IsPointInsideCollider(thisCornerBR);

    return collision;
}

bool CollisionBehavior::IsPointInsideCollider(Vector2 position) {
    float colliderBoundaryTop = this->parent->getPosition()->getY();
    float colliderBoundaryLeft = this->parent->getPosition()->getX();
    float colliderBoundaryRight =
        colliderBoundaryLeft + this->colliderSize->getX();
    float colliderBoundaryBottom =
        colliderBoundaryTop + this->colliderSize->getY();

    if (colliderBoundaryLeft <= position.getX() &&
        position.getX() <= colliderBoundaryRight &&
        colliderBoundaryTop <= position.getY() &&
        position.getY() <= colliderBoundaryBottom) {
        return true;
    }
    return false;
}

void CollisionBehavior::OnStart() {}

void CollisionBehavior::BeforeCollision(std::shared_ptr<GameObject> other) {
    std::cout << "Collision detected on: " << this->parent->getTag()
              << std::endl;
}
