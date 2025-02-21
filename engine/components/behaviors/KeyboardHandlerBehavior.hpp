#ifndef KEYBOARDHANDLERBEHAVIOR_HPP
#define KEYBOARDHANDLERBEHAVIOR_HPP

#include "Behavior.hpp"
#include <SDL3/SDL.h>

/**
 * @class KeyboardHandlerBehavior
 * @brief An abstract class for handling keyboard inputs
 *
 */
class KeyboardHandlerBehavior : public Behavior {
  public:
    /**
     * @brief Called when a key is pressed (or held) down
     *
     * @param e The key down event.
     */
    virtual void OnKeyDown(SDL_KeyboardEvent &e) = 0;
    /**
     * @brief Called when a key is released
     *
     * @param e The key released.
     */
    virtual void OnKeyUp(SDL_KeyboardEvent &e) = 0;
};

#endif // KEYBOARDHANDLERBEHAVIOR_HPP
