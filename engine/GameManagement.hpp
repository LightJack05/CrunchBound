#ifndef GAMEMANAGEMENT_HPP
#define GAMEMANAGEMENT_HPP

#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>

/**
 * @brief Enqueue a reset of the game to be performed on the next frame.
 */
void EnqueueGameReset();

/**
 * @brief Run the actions that have to be run every frame.
 */
void RunFrameActions();
#endif // GAMEMANAGEMENT_HPP
