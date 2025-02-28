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
     * @brief Whether the Left key is down
     */
    bool isLeftDown = false;
    /**
     * @brief Whether the Right key is down
     */
    bool isRightDown = false;
    /**
     * @brief Whether the Up key is down
     */
    bool isUpDown = false;
    /**
     * @brief The movement speed of the player
     */
    const float movementSpeed = 1;
    /**
     * @brief Called when the left key goes down
     */
    void OnLeftDown();
    /**
     * @brief Called when the right key goes down
     */
    void OnRightDown();
    /**
     * @brief Called when the left key goes up
     */
    void OnLeftUp();
    /**
     * @brief Called when the right key goes up
     */
    void OnRightUp();
    /**
     * @brief Called when the player jumps
     */
    void OnJump();

  public:
    PlayerKeyboardBehavior();
    ~PlayerKeyboardBehavior();
    virtual void OnKeyDown(SDL_KeyboardEvent &e) override;
    virtual void OnKeyUp(SDL_KeyboardEvent &e) override;
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // PLAYERKEYBOARDBEHAVIOR_HPP
