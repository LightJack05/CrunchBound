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
  protected:
    SDL_Renderer *renderer = nullptr;

  public:
    Renderer();
    Renderer(SDL_Renderer *renderer);
    ~Renderer();
};

#endif // RENDERER_HPP
