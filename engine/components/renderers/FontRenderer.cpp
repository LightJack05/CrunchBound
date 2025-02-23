#include "FontRenderer.hpp"
#include "../../../engine/AssetLoading.hpp"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>

FontRenderer::FontRenderer(std::string pathToFont, float size) {
    this->font = TTF_OpenFont(GetAssetPath(pathToFont).c_str(), size);
    this->renderable = std::make_shared<SDL_FRect>();
}

FontRenderer::~FontRenderer() {
    if (surface != nullptr) {
        SDL_DestroySurface(surface);
        surface = nullptr;
    }
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

void FontRenderer::OnTick() {
    this->renderable->x = this->parent->getPosition()->getX();
    this->renderable->y = this->parent->getPosition()->getY();
    if (surface != nullptr) {
        SDL_DestroySurface(surface);
    }
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
    surface = TTF_RenderText_Solid(font, text.c_str(), text.length(), *color);
    this->renderable->w = surface->w / 8.0;
    this->renderable->h = surface->h / 8.0;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
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
