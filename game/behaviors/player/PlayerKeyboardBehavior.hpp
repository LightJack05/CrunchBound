#ifndef PLAYERKEYBOARDBEHAVIOR_HPP
#define PLAYERKEYBOARDBEHAVIOR_HPP

#include "../../../engine/components/behaviors/KeyboardHandlerBehavior.hpp"

class PlayerKeyboardBehavior : public KeyboardHandlerBehavior {
  public:
    PlayerKeyboardBehavior();
    ~PlayerKeyboardBehavior();
    virtual void OnKeyDown(SDL_KeyboardEvent &e) override;
    virtual void OnKeyUp(SDL_KeyboardEvent &e) override;
    virtual void OnTick() override;
    virtual void OnStart() override;
};

#endif // PLAYERKEYBOARDBEHAVIOR_HPP
