#include "KeyboardHandling.hpp"
#include "GameManagement.hpp"
#include "components/GameObjectComponent.hpp"
#include "components/behaviors/KeyboardHandlerBehavior.hpp"
#include <SDL3/SDL_events.h>

void HandleKeyboardEvent(SDL_Event &e) {
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->components) {
            if (component->getEnabled()) {

                KeyboardHandlerBehavior *keyboardHandler =
                    dynamic_cast<KeyboardHandlerBehavior *>(component.get());
                if (keyboardHandler) {
                    if (e.type == SDL_EVENT_KEY_DOWN) {
                        keyboardHandler->OnKeyDown(e.key);
                    }
                    if (e.type == SDL_EVENT_KEY_UP) {
                        keyboardHandler->OnKeyUp(e.key);
                    }
                }

                component->OnTick();
            }
        }
    }
}
