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
    // Update the objects registered and work through the frame queue
    UpdateObjects();
    // If there has been a reset requested during this update cycle, run the
    // reset.
    ResetGameIfRequired();
}
