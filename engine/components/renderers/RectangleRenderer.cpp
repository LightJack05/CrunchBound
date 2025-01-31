#include "RectangleRenderer.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <memory>

RectangleRenderer::RectangleRenderer(GameObject *parent, float x, float y) {
        this->parent = parent;
        this->renderable = std::make_shared<SDL_FRect>();
        this->size->setX(x);
        this->size->setY(y);
        this->renderable->x = this->parent->getPosition()->getX();
        this->renderable->y = this->parent->getPosition()->getY();
        this->renderable->h = this->size->getY();
        this->renderable->w = this->size->getX();
}

RectangleRenderer::~RectangleRenderer() {}

void RectangleRenderer::Render(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b,
                               color->a);
        SDL_RenderFillRect(renderer, this->renderable.get());
}

void RectangleRenderer::OnTick() {
        this->renderable->h = this->size->getY();
        this->renderable->w = this->size->getX();
        this->renderable->x = this->parent->getPosition()->getX();
        this->renderable->y = this->parent->getPosition()->getY();
}

void RectangleRenderer::OnStart() {}

void RectangleRenderer::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        this->color->r = r;
        this->color->g = g;
        this->color->b = b;
        this->color->a = a;
}
