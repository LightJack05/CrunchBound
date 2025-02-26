#include "GameManagement.hpp"
#include "../game/Lifecycle.hpp"
#include "GameObject.hpp"
#include "ObjectManagement.hpp"
#include "components/GameObjectComponent.hpp"
#include "exceptions/GameObjectNotFoundException.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <iostream>
#include <memory>
#include <queue>

SDL_Renderer *GlobalRenderer;
static bool IsResetEnqueued = false;

std::shared_ptr<GameObject> GameManager;

SDL_Color WindowBackgroundColor;

bool QuitGame = false;
const int ScreenHeight = 1200;
const int ScreenWidth = 1600;


static void ResetGameIfRequired() {
    if (IsResetEnqueued) {
        ResetGame();
        IsResetEnqueued = false;
    }
}


void EnqueueGameReset() { IsResetEnqueued = true; }

void RunFrameActions() {
    UpdateObjects();
    ResetGameIfRequired();
}
