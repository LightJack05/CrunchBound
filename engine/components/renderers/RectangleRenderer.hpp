#ifndef RECTANGLERENDERER_HPP
#define RECTANGLERENDERER_HPP

#include "../../Vector2.hpp"
#include "Renderer.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <memory>

class RectangleRenderer : public Renderer {
      protected:
        std::shared_ptr<SDL_FRect> renderable = NULL;
        std::shared_ptr<Vector2> size = std::make_shared<Vector2>(0, 0);
        std::shared_ptr<SDL_Color> color = std::make_shared<SDL_Color>();

      public:
        RectangleRenderer(float width, float height);
        ~RectangleRenderer();

        void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        void Render(SDL_Renderer *renderer) override;
        void OnTick() override;
        void OnStart() override;
};

#endif // RECTANGLERENDERER_HPP
