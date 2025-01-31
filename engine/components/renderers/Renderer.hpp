#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "../../GameObjectComponent.hpp"
#include <SDL3/SDL_render.h>

class Renderer : public GameObjectComponent {
    public:
        Renderer();
        ~Renderer();
        virtual void Render(SDL_Renderer *renderer) = 0;

};

#endif // RENDERER_HPP
