#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Vector2.hpp"

class GameObject {
      protected:
        bool enabled = true;
        float weight = 0;

      public:
        bool getEnabled() const { return enabled; };
        void setEnabled(bool value) { weight = value; };
        float getWeight() const { return enabled; };
        void setWeight(float value) { weight = value; };
        Vector2 *getPosition() const;
        void setPosition(Vector2 *value);
        Vector2 *getScale() const;
        void setScale(Vector2 *value);
        Vector2 *getVelocity() const;
        void setVelocity(Vector2 *value);


        Vector2 *position = new Vector2();
        Vector2 *scale = new Vector2();
        Vector2 *velocity = new Vector2();

        GameObject();
        ~GameObject();
};

#endif // GAMEOBJECT_HPP
