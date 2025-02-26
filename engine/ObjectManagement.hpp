#ifndef OBJECTMANAGEMENT_HPP
#define OBJECTMANAGEMENT_HPP

#include "GameObject.hpp"
#include <memory>
#include <vector>

/**
 * @brief The list of existing gameobjects.
 *
 * @warning Please be careful when using directly, may cause the iterator to
 * crash!
 */
extern std::vector<std::shared_ptr<GameObject>> GameObjects;
/**
 * @brief Iterate over all objects, and update the appropriately, using OnTick()
 * or Component specific methods.
 *
 * @param renderer The renderer responsible for the application window.
 */
void UpdateObjects();

/**
 * @brief Enqueue an object to be registered on the next frame.
 *
 * @param object The object to be registered.
 */
void EnqueueRegisterGameObject(std::shared_ptr<GameObject> object);
/**
 * @brief Enqueue the destruction of a gameobject
 *
 * @param object The object to be destroyed
 */
void EnqueueDestroyGameObject(GameObject *object);

/**
 * @brief Initialize all gameobjects and call the OnStart() methods.
 */
void OnGameStart();

/**
 * @brief Try to get a gameobject by tag.
 *
 * @param tag The tag to search for.
 * @throws GameObjectNotFoundException if there is no object found.
 */
std::shared_ptr<GameObject> GetGameObjectByTag(std::string tag);

#endif // OBJECTMANAGEMENT_HPP
