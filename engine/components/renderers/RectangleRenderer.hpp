#ifndef RECTANGLERENDERER_HPP
#define RECTANGLERENDERER_HPP

#include "Renderer.hpp"
#include <SDL3/SDL_rect.h>
class RectangleRenderer : Renderer {
      protected:
        SDL_FRect *renderable = NULL;

      public:
        void Render(SDL_Renderer *renderer) override;
        SDL_FRect *getRenderable() const;
        void setRenderable(SDL_FRect *value);

        RectangleRenderer(SDL_FRect *renderable);
        ~RectangleRenderer();
};

#endif // RECTANGLERENDERER_HPP
