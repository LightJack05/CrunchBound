#include "RectangleRenderer.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <memory>

RectangleRenderer::RectangleRenderer(float width, float height) {
    this->renderable = std::make_shared<SDL_FRect>();
    this->size->setX(width);
    this->size->setY(height);
    this->renderable->h = this->size->getY();
    this->renderable->w = this->size->getX();
}

RectangleRenderer::~RectangleRenderer() {}

void RectangleRenderer::OnTick() {
    this->renderable->h = this->size->getY() * this->parent->getScale()->getY();
    this->renderable->w = this->size->getX() * this->parent->getScale()->getX();
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
    SDL_SetRenderDrawColor(this->renderer, color->r, color->g, color->b,
                           color->a);
    SDL_RenderFillRect(this->renderer, this->renderable.get());
}

void RectangleRenderer::OnStart() {
    this->renderable->h = this->size->getY() * this->parent->getScale()->getY();
    this->renderable->w = this->size->getX() * this->parent->getScale()->getX();
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
}

void RectangleRenderer::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->color->r = r;
    this->color->g = g;
    this->color->b = b;
    this->color->a = a;
}
