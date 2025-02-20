#include "PlayerKeyboardBehavior.hpp"
#include "../../../engine/components/behaviors/GravityBehavior.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>

static bool IsSpaceDown = false;
static bool IsADown = false;
static bool IsDDown = false;
static const float MovementSpeed = 1;

void PlayerKeyboardBehavior::OnKeyDown(SDL_KeyboardEvent &e) {
    if (e.key == SDLK_SPACE && !IsSpaceDown) {
        IsSpaceDown = true;
        this->parent->getVelocity()->setY(-2);
        this->parent->GetFirstComponent<GravityBehavior>()->setEnabled(true);
    }
    if (e.key == SDLK_A && !IsADown) {
        IsADown = true;
        this->parent->getVelocity()->setX(-MovementSpeed);
    }
    if (e.key == SDLK_D && !IsDDown) {
        IsDDown = true;
        this->parent->getVelocity()->setX(MovementSpeed);
    }
}

void PlayerKeyboardBehavior::OnKeyUp(SDL_KeyboardEvent &e) {
    if (e.key == SDLK_SPACE) {
        IsSpaceDown = false;
    }
    if (e.key == SDLK_A) {
        IsADown = false;
        if (!IsDDown)
            this->parent->getVelocity()->setX(0);
        else
            this->parent->getVelocity()->setX(MovementSpeed);
    }
    if (e.key == SDLK_D) {
        IsDDown = false;
        if (!IsADown)
            this->parent->getVelocity()->setX(0);
        else
            this->parent->getVelocity()->setX(-MovementSpeed);
    }
}

void PlayerKeyboardBehavior::OnTick() {}
void PlayerKeyboardBehavior::OnStart() {}

PlayerKeyboardBehavior::PlayerKeyboardBehavior() {}
PlayerKeyboardBehavior::~PlayerKeyboardBehavior() {}
