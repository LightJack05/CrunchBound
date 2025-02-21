#include "GameManagement.hpp"
#include "../game/Lifecycle.hpp"
#include "GameObject.hpp"
#include "components/GameObjectComponent.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <iostream>
#include <memory>
#include <queue>

SDL_Renderer *GlobalRenderer;
std::vector<std::shared_ptr<GameObject>> GameObjects;
static std::queue<std::shared_ptr<GameObject>> CreateObjectsQueue;
static std::queue<GameObject *> DestroyObjectsQueue;
static bool IsResetEnqueued = false;

std::shared_ptr<GameObject> GameManager;

SDL_Color WindowBackgroundColor;

bool QuitGame = false;
const int ScreenHeight = 1200;
const int ScreenWidth = 1600;

static void
HandleComponentUpdate(std::shared_ptr<GameObjectComponent> component) {
    component->OnTick();
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

static void ResetGameIfRequired() {
    if (IsResetEnqueued) {
        ResetGame();
        IsResetEnqueued = false;
    }
}

static void WorkThroughFrameQueue() {
    RegisterEnqueuedObjects();
    DestroyEnqueuedObjects();
    ResetGameIfRequired();
}

void UpdateObjects() {
    WorkThroughFrameQueue();
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->components) {
            if (component->getEnabled())
                HandleComponentUpdate(component);
        }
    }
}

void RegisterGameObject(std::shared_ptr<GameObject> object) {
    GameObjects.push_back(object);
}

void DestroyGameObject(GameObject *object) {
    for (int i = 0; i < GameObjects.size(); i++) {
        if (GameObjects.at(i).get() == object) {
            GameObjects.erase(GameObjects.begin() + i);
            return;
        }
    }
}

void EnqueueRegisterGameObject(std::shared_ptr<GameObject> object) {
    CreateObjectsQueue.push(object);
}

void EnqueueDestroyGameObject(GameObject *object) {
    DestroyObjectsQueue.push(object);
}

void EnqueueGameReset() { IsResetEnqueued = true; }

void OnGameStart() {
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->components) {
            component->OnStart();
        }
    }
}
