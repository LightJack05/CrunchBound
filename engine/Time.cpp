#include "Time.hpp"
#include <SDL3/SDL.h>

static unsigned int deltaTime = 1;
static unsigned int lastFrameTime = 0;
static unsigned long long timeSinceGameStart = 0;

unsigned int GetDeltaTime() { return deltaTime; }

void UpdateDeltaTime() {
    unsigned int currentFrameTime = SDL_GetTicks();
    deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;
    timeSinceGameStart += deltaTime;
}

unsigned long long GetTimeSinceGameStart() { return timeSinceGameStart; }
void ResetTimeSinceGameStart() {
    timeSinceGameStart = 0;
}
