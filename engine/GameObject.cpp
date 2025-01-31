#include "GameObject.hpp"
#include "GameObjectComponent.hpp"
#include "Vector2.hpp"

GameObject::GameObject() {}

GameObject::~GameObject() {}

std::shared_ptr<Vector2> GameObject::getPosition() const { return this->position; }
void GameObject::setPosition(std::shared_ptr<Vector2> value) {
        position = value;
}

std::shared_ptr<Vector2> GameObject::getScale() const { return scale; }
void GameObject::setScale(std::shared_ptr<Vector2> value) { scale = value; }

std::shared_ptr<Vector2> GameObject::getVelocity() const { return velocity; }
void GameObject::setVelocity(std::shared_ptr<Vector2> value) {
        velocity = value;
}

void GameObject::RegisterComponent(
    std::shared_ptr<GameObjectComponent> component) {
        this->components.push_back(component);
        component->setParent(this);
        
}
