#include "GameManagement.hpp"
#include "GameObject.hpp"
#include "components/GameObjectComponent.hpp"
#include "components/renderers/Renderer.hpp"
#include "../game/Lifecycle.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <iostream>
#include <memory>
#include <queue>

std::vector<std::shared_ptr<GameObject>> GameObjects;
static std::queue<std::shared_ptr<GameObject>> CreateObjectsQueue;
static bool IsResetEnqueued = false;

std::shared_ptr<GameObject> GameManager;

SDL_Color WindowBackgroundColor;

bool QuitGame = false;
const int ScreenHeight = 1200;
const int ScreenWidth = 1600;

static void
HandleComponentUpdate(std::shared_ptr<GameObjectComponent> component,
                      SDL_Renderer *renderer) {
    Renderer *r = dynamic_cast<Renderer *>(component.get());
    if (r) {
        r->Render(renderer);
    }

    component->OnTick();
}

static void RegisterEnqueuedObjects(){
    while(!CreateObjectsQueue.empty()){
        RegisterGameObject(CreateObjectsQueue.front());
        CreateObjectsQueue.pop();
    }
}
static void ResetGameIfRequired(){
    if(IsResetEnqueued){
        ResetGame();
        IsResetEnqueued = false;
    }
}

static void WorkThroughFrameQueue(){
    RegisterEnqueuedObjects();
    ResetGameIfRequired();
}

void UpdateObjects(SDL_Renderer *renderer) {
    WorkThroughFrameQueue();
    int i = 0;
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        i++;
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->components) {
            if (component->getEnabled())
                HandleComponentUpdate(component, renderer);
        }
    }
    SDL_SetRenderDrawColor(renderer, WindowBackgroundColor.r,
                           WindowBackgroundColor.g, WindowBackgroundColor.b,
                           WindowBackgroundColor.a);
}

void RegisterGameObject(std::shared_ptr<GameObject> object) {
    GameObjects.push_back(object);
}
void EnqueueRegisterGameObject(std::shared_ptr<GameObject> object){
    CreateObjectsQueue.push(object);
}
void EnqueueGameReset(){
    IsResetEnqueued = true;
}

void OnGameStart() {
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->components) {
            component->OnStart();
        }
    }
}
