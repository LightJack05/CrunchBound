#include "GameManagement.hpp"
#include "../game/Lifecycle.hpp"
#include "ObjectManagement.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>

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
