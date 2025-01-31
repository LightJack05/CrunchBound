#include "GameManagement.hpp"
#include "GameObjectComponent.hpp"
#include "components/renderers/Renderer.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <iostream>
#include <memory>

std::vector<std::shared_ptr<GameObject>> gameObjects =
    std::vector<std::shared_ptr<GameObject>>();

SDL_Color windowBackgroundColor;

static void
HandleComponentUpdate(std::shared_ptr<GameObjectComponent> component,
                      SDL_Renderer *renderer) {
        Renderer *r = dynamic_cast<Renderer *>(component.get());
        if (r) {
                r->Render(renderer);
        }
}

void UpdateObjects(SDL_Renderer *renderer) {
        for (const std::shared_ptr<GameObject> gameObject : gameObjects) {
                for (const std::shared_ptr<GameObjectComponent> component :
                     gameObject->components) {
                        HandleComponentUpdate(component, renderer);
                }
        }
        SDL_SetRenderDrawColor(renderer, windowBackgroundColor.r, windowBackgroundColor.g, windowBackgroundColor.b, windowBackgroundColor.a);
}

void RegisterGameObject(std::shared_ptr<GameObject> object) {
        gameObjects.push_back(object);
}
