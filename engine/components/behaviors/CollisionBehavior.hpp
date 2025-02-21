#ifndef COLLISIONBEHAVIOR_HPP
#define COLLISIONBEHAVIOR_HPP

#include "Behavior.hpp"
#include <memory>
/**
 * @class CollisionBehavior
 * @brief Controlls collision of an object with other objects that also have this or a child component
 *
 */
class CollisionBehavior : public Behavior {
  protected:
    /**
     * @brief The size of the area from the origin of the object in which collison checks will take place
     */
    std::shared_ptr<Vector2> colliderSize = std::make_shared<Vector2>();
    /**
     * @brief Check if this components parent will collide with the other object next frame 
     *
     * @param other The other GameObject
     * @return True if there is a collision next frame, otherwise false.
     */
    bool CheckForCollision(std::shared_ptr<GameObject> other);

  public:
    /**
     * @brief Check whether the point defined by the vector2 is inside the collider of this components parent
     *
     * @param position The position to check
     * @return True if the point is inside the collider, otherwise false.
     */
    bool IsPointInsideCollider(Vector2 position);
    void OnTick() override;
    void OnStart() override;
    const std::shared_ptr<Vector2> getColliderSize() { return colliderSize; }
    /**
     * @brief The action to be taken when the object will collide next frame.
     *
     * @param other The other object the current one collides with.
     */
    virtual void BeforeCollision(std::shared_ptr<GameObject> other);

    CollisionBehavior();
    CollisionBehavior(int x, int y);
};

#endif // COLLISIONBEHAVIOR_HPP
