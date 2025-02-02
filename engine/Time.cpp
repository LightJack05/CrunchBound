#include "Time.hpp"
#include <SDL3/SDL.h>

static unsigned int deltaTime = 1;
static unsigned int lastFrameTime = 0;

unsigned int GetDeltaTime() {
    return deltaTime;
}

void UpdateDeltaTime() {
    unsigned int currentFrameTime = SDL_GetTicks();
    deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;
}
