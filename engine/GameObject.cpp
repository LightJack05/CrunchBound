#include "GameObject.hpp"
#include "GameObjectComponent.hpp"
#include "Vector2.hpp"
#include "exceptions/ComponentNotFoundException.hpp"
#include <memory>

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

void GameObject::RemoveComponent(std::shared_ptr<GameObjectComponent> component) {
    for (int i = 0; i < this->components.size(); i++) {
        if(components.at(i) == component){
            components.erase(components.begin()+i);
            return;
        }    
    }

    throw ComponentNotFoundException(); 
}
