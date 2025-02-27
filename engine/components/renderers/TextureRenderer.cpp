#include "TextureRenderer.hpp"
#include "../../AssetLoading.hpp"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>

TextureRenderer::TextureRenderer(float width, float height,
                                 std::string pathToTexture) {
    this->renderable = std::make_shared<SDL_FRect>();
    // Load the texture from the appropriate path
    this->texture = IMG_LoadTexture(this->renderer, GetAssetPath(pathToTexture).c_str());
    // Use nearest neighbour scaling to avoid Anti-Aliasing / bluryness
    SDL_SetTextureScaleMode(this->texture, SDL_SCALEMODE_NEAREST);
    this->size->setX(width);
    this->size->setY(height);
    this->renderable->h = this->size->getY();
    this->renderable->w = this->size->getX();
}

TextureRenderer::~TextureRenderer() {
    // Destroy the texture to avoid leaks
    if (this->texture != nullptr) {
        SDL_DestroyTexture(this->texture);
        this->texture = nullptr;
    }
}

void TextureRenderer::OnTick() {
    this->renderable->h = this->size->getY() * this->parent->getScale()->getY();
    this->renderable->w = this->size->getX() * this->parent->getScale()->getX();
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
    // Render the texture
    SDL_RenderTexture(renderer, texture, nullptr, this->renderable.get());
}

void TextureRenderer::OnStart() {
    this->renderable->h = this->size->getY() * this->parent->getScale()->getY();
    this->renderable->w = this->size->getX() * this->parent->getScale()->getX();
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
}
