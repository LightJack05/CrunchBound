#include "FontRenderer.hpp"
#include "../../../engine/AssetLoading.hpp"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>

FontRenderer::FontRenderer(std::string pathToFont, float size) {
    // Open the TTF font file and create the rectangle for texture mapping
    this->font = TTF_OpenFont(GetAssetPath(pathToFont).c_str(), size);
    this->renderable = std::make_shared<SDL_FRect>();
}

FontRenderer::~FontRenderer() {
    // Destroy the surface and texture if necessary to avoid leaks
    if (surface != nullptr) {
        SDL_DestroySurface(surface);
        surface = nullptr;
    }
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    // Close the font
    TTF_CloseFont(this->font);
}

void FontRenderer::OnTick() {
    // Move the mapping rectangle to the parent position
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
    // Destroy any surface and texture if already present
    if (surface != nullptr) {
        SDL_DestroySurface(surface);
        surface = nullptr;
    }
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    // Create a surface from the text
    surface = TTF_RenderText_Solid(font, text.c_str(), text.length(), *color);
    // Scale down the surface by a factor of 8, to make it look smooth
    this->renderable->w = surface->w / 8.0;
    this->renderable->h = surface->h / 8.0;
    // Load the surface into GPU memory
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    // Register the texture for rendering
    SDL_RenderTexture(renderer, texture, NULL, renderable.get());
}

void FontRenderer::OnStart() {
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
}
void FontRenderer::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    this->color->r = r;
    this->color->g = g;
    this->color->b = b;
    this->color->a = a;
}
