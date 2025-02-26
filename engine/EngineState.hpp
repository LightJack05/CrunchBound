#ifndef ENGINESTATE_HPP
#define ENGINESTATE_HPP

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
const int ScreenHeight = 1200;
/**
 * @brief The width of the window/screen.
 */
const int ScreenWidth = 1600;
/**
 * @brief Whether to quit the game, will close the game on the next frame when
 * set to true.
 */
extern bool QuitGame;

#endif // ENGINESTATE_HPP
