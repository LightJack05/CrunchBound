#include "Renderer.hpp"
#include "../../GameManagement.hpp"
#include "../../EngineState.hpp"
#include <SDL3/SDL_render.h>

Renderer::Renderer() {
    this->renderer = GlobalRenderer;
}
Renderer::Renderer(SDL_Renderer *renderer) {
    this->renderer = renderer;
}
Renderer::~Renderer() {}
