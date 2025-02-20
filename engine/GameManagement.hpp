#ifndef GAMEMANAGEMENT_HPP
#define GAMEMANAGEMENT_HPP

#include "GameObject.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <vector>

/**
 * @brief The GameManager GameObject, used for generalized game control
 */
extern std::shared_ptr<GameObject> GameManager;
/**
 * @brief The list of existing gameobjects.
 *
 * @warning Please be careful when using directly, may cause the iterator to
 * crash!
 */
extern std::vector<std::shared_ptr<GameObject>> GameObjects;
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
 * @brief Iterate over all objects, and update the appropriately, using OnTick()
 * or Component specific methods.
 *
 * @param renderer The renderer responsible for the application window.
 */
void UpdateObjects(SDL_Renderer *renderer);

/**
 * @brief Directly register a gameobject. Will push the object into the
 * GameObjects vector.
 *
 * @param object The object to create.
 *
 * @warning May cause the application to crash if used from within a frame
 * update!
 */
void RegisterGameObject(std::shared_ptr<GameObject> object);
/**
 * @brief Enqueue an object to be registered on the next frame.
 *
 * @param object The object to be registered.
 */
void EnqueueRegisterGameObject(std::shared_ptr<GameObject> object);
/**
 * @brief Enqueue a reset of the game to be performed on the next frame.
 */
void EnqueueGameReset();
/**
 * @brief Initialize all gameobjects and call the OnStart() methods.
 */
void OnGameStart();

#endif // GAMEMANAGEMENT_HPP
