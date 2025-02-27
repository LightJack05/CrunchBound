#ifndef GAMEOBJECTCOMPONENT_HPP
#define GAMEOBJECTCOMPONENT_HPP

#include <cstddef>

#include "../GameObject.hpp"

/**
 * @class GameObjectComponent
 * @brief An abstract gameobject component. Has an OnTick and OnStart method.
 * Subclasses may be registered to a GameObject to perform certain actions.
 *
 */
class GameObjectComponent {
  protected:
    /**
     * @brief Whether to consider the component in Updates
     */
    bool enabled = true;
    /**
     * @brief The parent GameObject of the component
     */
    GameObject *parent = NULL;

  public:
    bool getEnabled() const { return enabled; }
    void setEnabled(bool value) { enabled = value; }
    void setParent(GameObject *value) { parent = value; }

    virtual ~GameObjectComponent();

    /**
     * @brief Executed every frame.
     */
    virtual void OnTick() = 0;
    /**
     * @brief Executed on game start.
     */
    virtual void OnStart() = 0;
};

#endif // GAMEOBJECTCOMPONENT_HPP
