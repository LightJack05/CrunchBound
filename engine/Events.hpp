#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SDL3/SDL_events.h>

/**
 * @brief Handles an event that has occoured.
 *
 * @param e The event that has occoured.
 */
void HandleEvent(SDL_Event& e);

#endif // EVENTS_HPP
