#ifndef GAMEMANAGERKEYBOARDHANDLER_HPP
#define GAMEMANAGERKEYBOARDHANDLER_HPP

#include "../../../engine/components/behaviors/KeyboardHandlerBehavior.hpp"

/**
 * @class GameManagerKeyboardBehavior
 * @brief The game managers keyboard handler for general handling
 *
 */
class GameManagerKeyboardBehavior : public KeyboardHandlerBehavior {
  public:
    GameManagerKeyboardBehavior();
    ~GameManagerKeyboardBehavior();
    virtual void OnKeyDown(SDL_KeyboardEvent &e) override;
    virtual void OnKeyUp(SDL_KeyboardEvent &e) override;
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // GAMEMANAGERKEYBOARDHANDLER_HPP
