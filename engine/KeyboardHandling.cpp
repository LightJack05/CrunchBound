#include "KeyboardHandling.hpp"
#include "ObjectManagement.hpp"
#include "components/GameObjectComponent.hpp"
#include "components/behaviors/KeyboardHandlerBehavior.hpp"
#include <SDL3/SDL_events.h>

void HandleKeyboardEvent(SDL_Event &e) {
    // Iterate over all GameObjectComponent on all GameObject
    for (const std::shared_ptr<GameObject> gameObject : GameObjects) {
        for (const std::shared_ptr<GameObjectComponent> component :
             gameObject->getComponents()) {
            // Check if the component is enabled
            if (component->getEnabled()) {
                // Cast the component down to a keyboard handler and, if it is,
                // call the OnKeyDown or OnKeyUp handler
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
            }
        }
    }
}
