#ifndef GAMEMANAGEMENT_HPP
#define GAMEMANAGEMENT_HPP

#include "GameObject.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <vector>

/**
 * @brief The renderer of the Game.
 */
extern SDL_Renderer *GlobalRenderer;
/**
 * @brief The GameManager GameObject, used for generalized game control
 */
extern std::shared_ptr<GameObject> GameManager;
/**
 * @brief The background color of the window.
 */
extern SDL_Color WindowBackgroundColor;
/**
 * @brief The height of the window/screen.
 */
extern const int ScreenHeight;
/**
 * @brief The width of the window/screen.
 */
extern const int ScreenWidth;
/**
 * @brief Whether to quit the game, will close the game on the next frame when
 * set to true.
 */
extern bool QuitGame;

/**
 * @brief Enqueue a reset of the game to be performed on the next frame.
 */
void EnqueueGameReset();

void RunFrameActions();
#endif // GAMEMANAGEMENT_HPP
