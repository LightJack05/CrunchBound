#include "PlayerKeyboardBehavior.hpp"
#include "../../../engine/components/behaviors/GravityBehavior.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>


bool IsSpaceDown = false;

void PlayerKeyboardBehavior::OnKeyDown(SDL_KeyboardEvent &e) {
    if (e.key == SDLK_SPACE && !IsSpaceDown) {
        IsSpaceDown = true;
        this->parent->getVelocity()->setY(-2);
        this->parent->GetFirstComponent<GravityBehavior>()->setEnabled(true);
    }
}

void PlayerKeyboardBehavior::OnKeyUp(SDL_KeyboardEvent &e) {
    if (e.key == SDLK_SPACE) {
        IsSpaceDown = false;
    }
}

void PlayerKeyboardBehavior::OnTick() {}
void PlayerKeyboardBehavior::OnStart() {}

PlayerKeyboardBehavior::PlayerKeyboardBehavior() {}
PlayerKeyboardBehavior::~PlayerKeyboardBehavior() {}
