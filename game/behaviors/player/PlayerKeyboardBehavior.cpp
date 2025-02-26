#include "PlayerKeyboardBehavior.hpp"
#include "../../../engine/EngineState.hpp"
#include "../../../engine/components/behaviors/GravityBehavior.hpp"
#include "PlayerBehavior.hpp"
#include "PlayerCollisionBehavior.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <memory>

void PlayerKeyboardBehavior::OnKeyDown(SDL_KeyboardEvent &e) {
    std::shared_ptr<PlayerBehavior> playerBehavior =
        this->parent->GetFirstComponent<PlayerBehavior>();
    if (e.key == SDLK_SPACE && !isSpaceDown) {
        isSpaceDown = true;
        if (playerBehavior->getJumpPoints() > 0) {
            this->parent->getVelocity()->setY(-2);
            this->parent->GetFirstComponent<GravityBehavior>()->setEnabled(
                true);
            playerBehavior->setJumpPoints(playerBehavior->getJumpPoints() - 1);
        }
    }
    if (e.key == SDLK_A && !isADown) {
        isADown = true;
        if (!(this->parent->getPosition()->getX() < 1)) {
            this->parent->getVelocity()->setX(-movementSpeed);
        }
    }
    if (e.key == SDLK_D && !isDDown) {
        isDDown = true;
        if (!((this->parent->getPosition()->getX() +
               this->parent->GetFirstComponent<PlayerCollisionBehavior>()
                   ->getColliderSize()
                   ->getX()) > ScreenWidth + 1)) {
            this->parent->getVelocity()->setX(movementSpeed);
        }
    }
}

void PlayerKeyboardBehavior::OnKeyUp(SDL_KeyboardEvent &e) {
    if (e.key == SDLK_SPACE) {
        isSpaceDown = false;
    }
    if (e.key == SDLK_A) {
        isADown = false;
        if (!isDDown)
            this->parent->getVelocity()->setX(0);
        else
            this->parent->getVelocity()->setX(movementSpeed);
    }
    if (e.key == SDLK_D) {
        isDDown = false;
        if (!isADown)
            this->parent->getVelocity()->setX(0);
        else
            this->parent->getVelocity()->setX(-movementSpeed);
    }
}

void PlayerKeyboardBehavior::OnTick() {}
void PlayerKeyboardBehavior::OnStart() {}

PlayerKeyboardBehavior::PlayerKeyboardBehavior() {}
PlayerKeyboardBehavior::~PlayerKeyboardBehavior() {}
