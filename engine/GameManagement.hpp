#ifndef GAMEMANAGEMENT_HPP
#define GAMEMANAGEMENT_HPP

#include "GameObject.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <vector>


/**
 * @brief Enqueue a reset of the game to be performed on the next frame.
 */
void EnqueueGameReset();

void RunFrameActions();
#endif // GAMEMANAGEMENT_HPP
