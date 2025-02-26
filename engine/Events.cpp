#include "Events.hpp"
#include "../engine/EngineState.hpp"
#include "KeyboardHandling.hpp"
#include <SDL3/SDL_events.h>

void HandleEvent(SDL_Event &e) {
    if (e.type == SDL_EVENT_QUIT) {
        QuitGame = true;
    }
    if (e.type == SDL_EVENT_KEY_DOWN || e.type == SDL_EVENT_KEY_UP) {
        HandleKeyboardEvent(e);
    }
}
