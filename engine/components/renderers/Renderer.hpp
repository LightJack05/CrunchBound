#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "../GameObjectComponent.hpp"
#include <SDL3/SDL_render.h>

/**
 * @class Renderer
 * @brief Abstract renderer component
 *
 */
class Renderer : public GameObjectComponent {
  public:
    Renderer();
    ~Renderer();
    /**
     * @brief Render the object to the screen
     *
     * @param renderer The renderer to render the object to
     */
    virtual void Render(SDL_Renderer *renderer) = 0;
};

#endif // RENDERER_HPP
