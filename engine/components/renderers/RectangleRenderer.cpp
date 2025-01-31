#include "RectangleRenderer.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

RectangleRenderer::RectangleRenderer(SDL_FRect *renderable){
    this->renderable = renderable;
}

RectangleRenderer::~RectangleRenderer(){
    delete renderable;
}

SDL_FRect *RectangleRenderer::getRenderable() const{
    return renderable;
}

void RectangleRenderer::setRenderable(SDL_FRect *value) {
    delete renderable;
    renderable = value;
}

void RectangleRenderer::Render(SDL_Renderer *renderer) {
    SDL_RenderFillRect(renderer, this->renderable);
}
