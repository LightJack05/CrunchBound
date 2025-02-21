#include "TextureRenderer.hpp"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>

TextureRenderer::TextureRenderer(float width, float height,
                                 std::string pathToTexture) {
    this->renderable = std::make_shared<SDL_FRect>();
    this->texture = IMG_LoadTexture(this->renderer, pathToTexture.c_str());
    this->size->setX(width);
    this->size->setY(height);
    this->renderable->h = this->size->getY();
    this->renderable->w = this->size->getX();
}

TextureRenderer::~TextureRenderer() { SDL_DestroyTexture(this->texture); }

void TextureRenderer::OnTick() {
    SDL_RenderTexture(renderer, texture, nullptr, this->renderable.get());
    this->renderable->h = this->size->getY() * this->parent->getScale()->getY();
    this->renderable->w = this->size->getX() * this->parent->getScale()->getX();
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
}

void TextureRenderer::OnStart() {
    this->renderable->h = this->size->getY() * this->parent->getScale()->getY();
    this->renderable->w = this->size->getX() * this->parent->getScale()->getX();
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
}

void TextureRenderer::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->color->r = r;
    this->color->g = g;
    this->color->b = b;
    this->color->a = a;
}
