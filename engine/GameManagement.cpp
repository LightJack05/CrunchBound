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

static bool IsResetEnqueued = false;

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
