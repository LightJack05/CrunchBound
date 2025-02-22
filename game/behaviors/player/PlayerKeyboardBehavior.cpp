#include "PlayerKeyboardBehavior.hpp"
#include "../../../engine/GameManagement.hpp"
#include "../../../engine/components/behaviors/GravityBehavior.hpp"
#include "PlayerBehavior.hpp"
#include "PlayerCollisionBehavior.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <memory>

static bool IsSpaceDown = false;
static bool IsADown = false;
static bool IsDDown = false;
static const float MovementSpeed = 1;

void PlayerKeyboardBehavior::OnKeyDown(SDL_KeyboardEvent &e) {
    std::shared_ptr<PlayerBehavior> playerBehavior =
        this->parent->GetFirstComponent<PlayerBehavior>();
    if (e.key == SDLK_SPACE && !IsSpaceDown) {
        IsSpaceDown = true;
        if (playerBehavior->getJumpPoints() > 0) {
            this->parent->getVelocity()->setY(-2);
            this->parent->GetFirstComponent<GravityBehavior>()->setEnabled(
                true);
            playerBehavior->setJumpPoints(playerBehavior->getJumpPoints() - 1);
        }
    }
    if (e.key == SDLK_A && !IsADown) {
        IsADown = true;
        if (!(this->parent->getPosition()->getX() < 1)) {
            this->parent->getVelocity()->setX(-MovementSpeed);
        }
    }
    if (e.key == SDLK_D && !IsDDown) {
        IsDDown = true;
        if (!((this->parent->getPosition()->getX() +
               this->parent->GetFirstComponent<PlayerCollisionBehavior>()
                   ->getColliderSize()
                   ->getX()) > ScreenWidth + 1)) {
            this->parent->getVelocity()->setX(MovementSpeed);
        }
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
