#include "PlayerKeyboardBehavior.hpp"
#include "../../../engine/EngineState.hpp"
#include "../../../engine/components/behaviors/GravityBehavior.hpp"
#include "PlayerBehavior.hpp"
#include "PlayerCollisionBehavior.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <memory>

void PlayerKeyboardBehavior::OnLeftDown() {
    if (!(this->parent->getPosition()->getX() < 1)) {
        this->parent->getVelocity()->setX(-movementSpeed);
    }
}
void PlayerKeyboardBehavior::OnRightDown() {
    if (!((this->parent->getPosition()->getX() +
           this->parent->GetFirstComponent<PlayerCollisionBehavior>()
               ->getColliderSize()
               ->getX()) > ScreenWidth + 1)) {
        this->parent->getVelocity()->setX(movementSpeed);
    }
}
void PlayerKeyboardBehavior::OnJump() {
    std::shared_ptr<PlayerBehavior> playerBehavior =
        this->parent->GetFirstComponent<PlayerBehavior>();
    // .. if the player still has jump points...
    if (playerBehavior->getJumpPoints() > 0) {
        // ... jump and reenable gravity ...
        this->parent->getVelocity()->setY(-2);
        this->parent->GetFirstComponent<GravityBehavior>()->setEnabled(true);
        // ... and decrease the jump points.
        playerBehavior->setJumpPoints(playerBehavior->getJumpPoints() - 1);
    }
}

void PlayerKeyboardBehavior::OnKeyDown(SDL_KeyboardEvent &e) {
    // On space down...
    if (e.key == SDLK_SPACE && !isSpaceDown) {
        isSpaceDown = true;
        OnJump();
    }
    if (e.key == SDLK_UP && !isUpDown) {
        isUpDown = true;
        OnJump();
    }
    // move left and right with A and D, and make sure the player doesn't go off
    // screen.
    if (e.key == SDLK_A && !isADown) {
        isADown = true;
        OnLeftDown();
    }
    if (e.key == SDLK_LEFT && !isLeftDown) {
        isLeftDown = true;
        OnLeftDown();
    }
    if (e.key == SDLK_D && !isDDown) {
        isDDown = true;
        OnRightDown();
    }
    if (e.key == SDLK_RIGHT && !isRightDown) {
        isRightDown = true;
        OnRightDown();
    }
}

void PlayerKeyboardBehavior::OnRightUp() {
    if (!isADown && !isLeftDown)
        this->parent->getVelocity()->setX(0);
    else
        this->parent->getVelocity()->setX(-movementSpeed);
}
void PlayerKeyboardBehavior::OnLeftUp() {
    if (!isDDown && !isRightDown)
        this->parent->getVelocity()->setX(0);
    else
        this->parent->getVelocity()->setX(movementSpeed);
}

void PlayerKeyboardBehavior::OnKeyUp(SDL_KeyboardEvent &e) {
    // Reset the keys on up events.
    if (e.key == SDLK_SPACE) {
        isSpaceDown = false;
    }
    if (e.key == SDLK_UP) {
        isUpDown = false;
    }
    // Reset movement speeds if no key is pressed, or invert it if the other key
    // is still down.
    if (e.key == SDLK_A) {
        isADown = false;
        OnLeftUp();
    }
    if (e.key == SDLK_LEFT) {
        isLeftDown = false;
        OnLeftUp();
    }
    if (e.key == SDLK_D) {
        isDDown = false;
        OnRightUp();
    }
    if (e.key == SDLK_RIGHT) {
        isRightDown = false;
        OnRightUp();
    }
}

void PlayerKeyboardBehavior::OnTick() {}
void PlayerKeyboardBehavior::OnStart() {}

PlayerKeyboardBehavior::PlayerKeyboardBehavior() {}
PlayerKeyboardBehavior::~PlayerKeyboardBehavior() {}
