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
    this->renderable->h = this->size->getY() * this->parent->getScale()->getY();
    this->renderable->w = this->size->getX() * this->parent->getScale()->getX();
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
    SDL_RenderTexture(renderer, texture, nullptr, this->renderable.get());
}

void TextureRenderer::OnStart() {
    this->renderable->h = this->size->getY() * this->parent->getScale()->getY();
    this->renderable->w = this->size->getX() * this->parent->getScale()->getX();
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
}

