#include "engine/GameManagement.hpp"
#include "engine/GameObject.hpp"
#include "engine/components/renderers/RectangleRenderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <iostream>
#include <memory>
#include <stdbool.h>
#include <stdlib.h>

void frame(SDL_Renderer *&ren) { UpdateObjects(ren); }

void gameLoop(SDL_Renderer *&ren) {
        SDL_Event e;
        bool quit = false;
        while (!quit) {
                while (SDL_PollEvent(&e)) {
                        if (e.type == SDL_EVENT_QUIT) {
                                quit = true;
                        }
                }
                SDL_RenderClear(ren);
                frame(ren);
                SDL_RenderPresent(ren);
                // avoid windows thinking the window has crashed.
                SDL_Delay(10);
        }
}

void initializeGame() {
        windowBackgroundColor.r = 255;
        windowBackgroundColor.b = 255;
        windowBackgroundColor.g = 255;
        windowBackgroundColor.a = 255;

        std::shared_ptr<GameObject> go = std::make_shared<GameObject>();
        go->setPosition(std::make_shared<Vector2>(300, 300));

        std::shared_ptr<RectangleRenderer> rr =
            std::make_shared<RectangleRenderer>(200, 200);
        rr->setColor(255, 0, 0, 255);
        go->RegisterComponent(rr);

        RegisterGameObject(go);
        OnGameStart(); 
}

int main() {
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
                fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
                return EXIT_FAILURE;
        }

        SDL_Window *win;
        SDL_Renderer *ren;
        if (SDL_CreateWindowAndRenderer("", 2000, 1200, SDL_WINDOW_RESIZABLE,
                                        &win, &ren) == 0) {
                fprintf(stderr, "SDL_CreateWindowAndRenderer Error:%s\n",
                        SDL_GetError());
                SDL_Quit();
                return EXIT_FAILURE;
        }

        initializeGame();

        gameLoop(ren);

        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return EXIT_SUCCESS;
}
