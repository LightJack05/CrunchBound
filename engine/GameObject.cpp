#include "GameObject.hpp"
#include "Vector2.hpp"

GameObject::GameObject() {}

GameObject::~GameObject() {
        delete this->scale;
        delete this->position;
        delete this->velocity;
}

Vector2 *GameObject::getPosition() const {
    return position;
}
void GameObject::setPosition(Vector2 *value) {
    delete position;
    position = value;
}


Vector2 *GameObject::getScale() const {
    return scale;
}
void GameObject::setScale(Vector2 *value) {
    delete scale;
    scale = value;
}


Vector2 *GameObject::getVelocity() const {
    return velocity;
}
void GameObject::setVelocity(Vector2 *value) {
    delete velocity;
    velocity = value;
}
