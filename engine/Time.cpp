#include "Time.hpp"
#include <SDL3/SDL.h>

static float deltaTime = 1;
static float lastFrameTime = 0;

float GetDeltaTime() {
    return deltaTime;

}

void UpdateDeltaTime() {
    unsigned int currentFrameTime = SDL_GetTicks();
    deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;
}
