#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Vector2.hpp"
#include "exceptions/ComponentNotFoundException.hpp"
#include <memory>
#include <string>
#include <vector>

class GameObjectComponent;

/**
 * @class GameObject
 * @brief A GameObject that represents an individual object in the game.
 *
 */
class GameObject {
  protected:
    /**
     * @brief Whether the gameobject should be considered for updates and other actions
     */
    bool enabled = true;
    /**
     * @brief The weight of the gameobject, may be used in physics
     */
    float weight = 0;
    /**
     * @brief The position of the gameobject
     */
    std::shared_ptr<Vector2> position = std::make_shared<Vector2>();
    /**
     * @brief The scale factor of the gameobject
     */
    std::shared_ptr<Vector2> scale = std::make_shared<Vector2>();
    /**
     * @brief The velocity of the gameobject
     */
    std::shared_ptr<Vector2> velocity = std::make_shared<Vector2>();
    /**
     * @brief The tag of the object, used for identification and classification
     */
    std::string tag = "";

  public:
    /**
     * @brief Components of the GameObject will be placed in here.
     *
     * @warning May cause problems when modified while the object is modified.
     */
    std::vector<std::shared_ptr<GameObjectComponent>> components;

    const std::string getTag() const { return tag; }
    void setTag(std::string value) { tag = value; }

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
    virtual ~GameObject();

    /**
     * @brief Add a component to the gameobject
     *
     * @param component The component to add. 
     */
    void RegisterComponent(std::shared_ptr<GameObjectComponent> component);
    /**
     * @brief Remove a component from the gameobject
     *
     * @param component The component to remove
     */
    void RemoveComponent(std::shared_ptr<GameObjectComponent> component);

    /**
     * @brief Get the first component that matches the type T
     *
     * @tparam T The type of the component
     * @return The first component on the gameobject matching type T
     */
    template <typename T> std::shared_ptr<T> GetFirstComponent() {
        for (const std::shared_ptr<GameObjectComponent> component :
             this->components) {

            T *r = dynamic_cast<T *>(component.get());
            if (r) {
                return std::dynamic_pointer_cast<T>(component);
            }
        }
        throw ComponentNotFoundException();
    }
};

#endif // GAMEOBJECT_HPP
