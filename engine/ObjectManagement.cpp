#include "ObjectManagement.hpp"
#include "components/GameObjectComponent.hpp"
#include "exceptions/GameObjectNotFoundException.hpp"
#include <queue>

std::vector<std::shared_ptr<GameObject>> GameObjects;
static std::queue<std::shared_ptr<GameObject>> CreateObjectsQueue;
static std::queue<GameObject *> DestroyObjectsQueue;

static void
HandleComponentUpdate(std::shared_ptr<GameObjectComponent> component) {
    // Run the OnTick handler on the component
    component->OnTick();
}

static void DestroyGameObject(GameObject *object) {
    // Find the index in the vector matching the pointer address passed, and erase that in the vector
    for (int i = 0; i < GameObjects.size(); i++) {
        if (GameObjects.at(i).get() == object) {
            GameObjects.erase(GameObjects.begin() + i);
            return;
        }
    }
}

static void RegisterGameObject(std::shared_ptr<GameObject> object) {
    GameObjects.push_back(object);
}

static void RegisterEnqueuedObjects() {
    while (!CreateObjectsQueue.empty()) {
        RegisterGameObject(CreateObjectsQueue.front());
        CreateObjectsQueue.pop();
    }
}

static void DestroyEnqueuedObjects() {
    while (!DestroyObjectsQueue.empty()) {
        DestroyGameObject(DestroyObjectsQueue.front());
        DestroyObjectsQueue.pop();
    }
}

static void WorkThroughFrameQueue() {
    // Register or Destroy any objects queued
    RegisterEnqueuedObjects();
    DestroyEnqueuedObjects();
}

void UpdateObjects() {
    // Work through any queued objects before starting the loop
    WorkThroughFrameQueue();
    // On all objects and components, perform a component update
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->getComponents()) {
            if (component->getEnabled())
                HandleComponentUpdate(component);
        }
    }
}

void EnqueueRegisterGameObject(std::shared_ptr<GameObject> object) {
    CreateObjectsQueue.push(object);
}

void EnqueueDestroyGameObject(GameObject *object) {
    DestroyObjectsQueue.push(object);
}

void OnGameStart() {
    // Iterate over all gameobjects and components, and run OnStart
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->getComponents()) {
            component->OnStart();
        }
    }
}

std::shared_ptr<GameObject> GetGameObjectByTag(std::string tag) {
    // Iterate through all objects until a gameobject with a matching tag is found, and then return it
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        if (gameObject->getTag() == tag) {
            return gameObject;
        }
    }
    throw GameObjectNotFoundException();
}
