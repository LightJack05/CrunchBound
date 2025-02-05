#ifndef GAMEOBJECTCOMPONENT_HPP
#define GAMEOBJECTCOMPONENT_HPP

#include <cstddef>

#include "../GameObject.hpp"

class GameObjectComponent {
  protected:
    bool enabled = true;
    GameObject *parent = NULL;

  public:
    bool getEnabled() const { return enabled; }
    void setEnabled(bool value) { enabled = value; }
    void setParent(GameObject *value) { parent = value; }

    ~GameObjectComponent();

    virtual void OnTick() = 0;
    virtual void OnStart() = 0;
};

#endif // GAMEOBJECTCOMPONENT_HPP
