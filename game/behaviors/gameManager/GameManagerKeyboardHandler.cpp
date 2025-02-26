#include "GameManagerKeyboardHandler.hpp"
#include "../../../engine/GameManagement.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>

void GameManagerKeyboardBehavior::OnKeyDown(SDL_KeyboardEvent &e) {
    if (e.key == SDLK_R && !isRDown) {
        isRDown = true;
        EnqueueGameReset();
    }
}

void GameManagerKeyboardBehavior::OnKeyUp(SDL_KeyboardEvent &e) {
    if (e.key == SDLK_R) {
        isRDown = false;
    }
}

void GameManagerKeyboardBehavior::OnTick() {}
void GameManagerKeyboardBehavior::OnStart() {}

GameManagerKeyboardBehavior::GameManagerKeyboardBehavior() {}
GameManagerKeyboardBehavior::~GameManagerKeyboardBehavior() {}
