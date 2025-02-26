#ifndef PLAYERKEYBOARDBEHAVIOR_HPP
#define PLAYERKEYBOARDBEHAVIOR_HPP

#include "../../../engine/components/behaviors/KeyboardHandlerBehavior.hpp"

/**
 * @class PlayerKeyboardBehavior
 * @brief The keyboard handler for the player
 *
 */
class PlayerKeyboardBehavior : public KeyboardHandlerBehavior {
  protected:
    /**
     * @brief Whether the space key is currently held down
     */
    bool isSpaceDown = false;
    /**
     * @brief Whether the A key is currently held down
     */
    bool isADown = false;
    /**
     * @brief Whether the D key is currently held down
     */
    bool isDDown = false;
    /**
     * @brief The movement speed of the player
     */
    const float movementSpeed = 1;

  public:
    PlayerKeyboardBehavior();
    ~PlayerKeyboardBehavior();
    virtual void OnKeyDown(SDL_KeyboardEvent &e) override;
    virtual void OnKeyUp(SDL_KeyboardEvent &e) override;
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // PLAYERKEYBOARDBEHAVIOR_HPP
