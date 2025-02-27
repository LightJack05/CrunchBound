#include "CollisionBehavior.hpp"
#include "../../ObjectManagement.hpp"
#include "../../Time.hpp"
#include <cstdio>
#include <memory>

CollisionBehavior::CollisionBehavior() {}

CollisionBehavior::CollisionBehavior(int x, int y) {
    this->colliderSize->setX(x);
    this->colliderSize->setY(y);
}

void CollisionBehavior::OnTick() {
    // Check for a collision with any other object
    for (const std::shared_ptr<GameObject> other : GameObjects) {
        // Skip the own parent object
        if (other.get() == this->parent) {
            continue;
        }
        // If there is a collision detected, call BeforeCollision with the other
        // object
        if (CheckForCollision(other)) {
            this->BeforeCollision(other);
        }
    }
}

bool CollisionBehavior::CheckForCollision(std::shared_ptr<GameObject> other) {
    // get the collider of the other object
    std::shared_ptr<CollisionBehavior> collider;
    try {
        collider = other->GetFirstComponent<CollisionBehavior>();
    } catch (ComponentNotFoundException) {
        return false;
    }

    // Get the parent origin and velocity
    Vector2 parentOrigin = *this->parent->getPosition();
    Vector2 parentVelocity = *this->parent->getVelocity();
    // Calculate the position change for this frame
    float positionChangeX = parent->getVelocity()->getX() * GetDeltaTime();
    float positionChangeY = parent->getVelocity()->getY() * GetDeltaTime();

    // Calculate the 4 corners of this object in the next frame by offsetting
    // them by the position change
    Vector2 thisCornerTL = Vector2(parentOrigin.getX() + positionChangeX,
                                   parentOrigin.getY() + positionChangeY);
    Vector2 thisCornerTR = Vector2(
        parentOrigin.getX() +
            (this->colliderSize->getX() * this->parent->getScale()->getX()) +
            positionChangeX,
        parentOrigin.getY() + positionChangeY);
    Vector2 thisCornerBL = Vector2(
        parentOrigin.getX() + positionChangeX,
        parentOrigin.getY() +
            (this->colliderSize->getY() * this->parent->getScale()->getY()) +
            positionChangeY);
    Vector2 thisCornerBR = Vector2(
        parentOrigin.getX() +
            (this->colliderSize->getX() * this->parent->getScale()->getX()) +
            positionChangeX,
        parentOrigin.getY() +
            (this->colliderSize->getY() * this->parent->getScale()->getY()) +
            positionChangeY);

    bool collision = false;

    // For all 4 corners, check if any of them wil be inside the collider of the
    // other object in the next frame
    collision = collision ?: collider->IsPointInsideCollider(thisCornerTL);
    collision = collision ?: collider->IsPointInsideCollider(thisCornerBL);
    collision = collision ?: collider->IsPointInsideCollider(thisCornerTR);
    collision = collision ?: collider->IsPointInsideCollider(thisCornerBR);

    return collision;
}

bool CollisionBehavior::IsPointInsideCollider(Vector2 position) {
    // Calculate the collider boundaries based on origin and size
    float colliderBoundaryTop = this->parent->getPosition()->getY();
    float colliderBoundaryLeft = this->parent->getPosition()->getX();
    float colliderBoundaryRight =
        colliderBoundaryLeft +
        (this->colliderSize->getX() * this->parent->getScale()->getX());
    float colliderBoundaryBottom =
        colliderBoundaryTop +
        (this->colliderSize->getY() * this->parent->getScale()->getY());

    // Check if the vector is between the boundaries
    if (colliderBoundaryLeft <= position.getX() &&
        position.getX() <= colliderBoundaryRight &&
        colliderBoundaryTop <= position.getY() &&
        position.getY() <= colliderBoundaryBottom) {
        return true;
    }
    return false;
}

void CollisionBehavior::OnStart() {}

void CollisionBehavior::BeforeCollision(std::shared_ptr<GameObject> other) {}
