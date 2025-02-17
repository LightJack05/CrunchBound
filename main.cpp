#include "engine/GameManagement.hpp"
#include "engine/Time.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <cstdlib>
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include "game/Init.hpp"

void frame(SDL_Renderer *&ren) {
    UpdateObjects(ren); 
}

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
        UpdateDeltaTime();
        frame(ren);
        SDL_RenderPresent(ren);
        // avoid windows thinking the window has crashed.
        SDL_Delay(10);
    }
}


int main() {
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *win;
    SDL_Renderer *ren;
    if (SDL_CreateWindowAndRenderer(
            "", ScreenWidth, ScreenHeight, SDL_WINDOW_BORDERLESS, &win, &ren) == 0) {
        fprintf(stderr, "SDL_CreateWindowAndRenderer Error:%s\n",
                SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    InitializeGame();

    OnGameStart();

    gameLoop(ren);

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return EXIT_SUCCESS;
}
