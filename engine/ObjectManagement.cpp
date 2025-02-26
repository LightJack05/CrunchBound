#include "ObjectManagement.hpp"
#include "components/GameObjectComponent.hpp"
#include "exceptions/GameObjectNotFoundException.hpp"
#include <queue>

std::vector<std::shared_ptr<GameObject>> GameObjects;
static std::queue<std::shared_ptr<GameObject>> CreateObjectsQueue;
static std::queue<GameObject *> DestroyObjectsQueue;

static void
HandleComponentUpdate(std::shared_ptr<GameObjectComponent> component) {
    component->OnTick();
}

static void DestroyGameObject(GameObject *object) {
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
    RegisterEnqueuedObjects();
    DestroyEnqueuedObjects();
}

void UpdateObjects() {
    WorkThroughFrameQueue();
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
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->getComponents()) {
            component->OnStart();
        }
    }
}

std::shared_ptr<GameObject> GetGameObjectByTag(std::string tag) {
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        if (gameObject->getTag() == tag) {
            return gameObject;
        }
    }
    throw GameObjectNotFoundException();
}
