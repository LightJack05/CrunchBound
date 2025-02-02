#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Vector2.hpp"
#include <memory>
#include <vector>

class GameObjectComponent;

class GameObject {
      protected:
        bool enabled = true;
        float weight = 0;
        std::shared_ptr<Vector2> position = std::make_shared<Vector2>();
        std::shared_ptr<Vector2> scale = std::make_shared<Vector2>();
        std::shared_ptr<Vector2> velocity = std::make_shared<Vector2>();

      public:
        std::vector<std::shared_ptr<GameObjectComponent>> components;

        bool getEnabled() const { return enabled; };
        void setEnabled(bool value) { weight = value; };

        float getWeight() const { return enabled; };
        void setWeight(float value) { weight = value; };

        std::shared_ptr<Vector2> getPosition() const;
        void setPosition(std::shared_ptr<Vector2> value);

        std::shared_ptr<Vector2> getScale() const;
        void setScale(std::shared_ptr<Vector2> value);

        std::shared_ptr<Vector2> getVelocity() const;
        void setVelocity(std::shared_ptr<Vector2> value);


        GameObject();
        ~GameObject();

        void RegisterComponent(std::shared_ptr<GameObjectComponent> component);
        void RemoveComponent(std::shared_ptr<GameObjectComponent> component);
};

#endif // GAMEOBJECT_HPP
