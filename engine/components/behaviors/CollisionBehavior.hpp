#ifndef COLLISIONBEHAVIOR_HPP
#define COLLISIONBEHAVIOR_HPP

#include "Behavior.hpp"
#include <memory>
class CollisionBehavior : public Behavior {
  protected:
    std::shared_ptr<Vector2> colliderSize = std::make_shared<Vector2>();
    bool CheckForCollision(std::shared_ptr<GameObject> other);

  public:
    bool IsPointInsideCollider(Vector2 position);
    void OnTick() override;
    void OnStart() override;
    const std::shared_ptr<Vector2> GetColliderSize() { return colliderSize; }
    virtual void BeforeCollision(std::shared_ptr<GameObject> other);

    CollisionBehavior();
    CollisionBehavior(int x, int y);
};

#endif // COLLISIONBEHAVIOR_HPP
