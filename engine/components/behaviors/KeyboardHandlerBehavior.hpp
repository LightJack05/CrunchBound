#ifndef KEYBOARDHANDLERBEHAVIOR_HPP
#define KEYBOARDHANDLERBEHAVIOR_HPP

#include "Behavior.hpp"
#include <SDL3/SDL.h>

class KeyboardHandlerBehavior : public Behavior {
  public:
    virtual void OnKeyDown(SDL_KeyboardEvent &e) = 0;
    virtual void OnKeyUp(SDL_KeyboardEvent &e) = 0;
};

#endif // KEYBOARDHANDLERBEHAVIOR_HPP
