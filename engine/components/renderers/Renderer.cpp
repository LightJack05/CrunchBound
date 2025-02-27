#include "Renderer.hpp"
#include "../../EngineState.hpp"
#include <SDL3/SDL_render.h>

Renderer::Renderer() {
    // By default, use the global renderer
    this->renderer = GlobalRenderer;
}
Renderer::Renderer(SDL_Renderer *renderer) {
    this->renderer = renderer;
}
Renderer::~Renderer() {}
