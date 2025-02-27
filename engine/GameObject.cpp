#include "GameObject.hpp"
#include "Vector2.hpp"
#include "components/GameObjectComponent.hpp"
#include "exceptions/ComponentNotFoundException.hpp"
#include <memory>

GameObject::GameObject() {}

GameObject::~GameObject() {}

std::shared_ptr<Vector2> GameObject::getPosition() const {
    return this->position;
}
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
    // Set the GameObjectComponent's parent to allow it to refrence back
    component->setParent(this);
}

void GameObject::RemoveComponent(
    std::shared_ptr<GameObjectComponent> component) {
    // Remove the component that matches the pointer address passed.
    for (int i = 0; i < this->components.size(); i++) {
        if (components.at(i) == component) {
            components.erase(components.begin() + i);
            return;
        }
    }

    throw ComponentNotFoundException();
}
