#include "GameManagement.hpp"
#include "GameObject.hpp"
#include "components/GameObjectComponent.hpp"
#include "components/renderers/Renderer.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <memory>

std::vector<std::shared_ptr<GameObject>> GameObjects =
    std::vector<std::shared_ptr<GameObject>>();

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

void UpdateObjects(SDL_Renderer *renderer) {

    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
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

void OnGameStart() {
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->components) {
            component->OnStart();
        }
    }
}
