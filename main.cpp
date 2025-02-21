#include "engine/Events.hpp"
#include "engine/GameManagement.hpp"
#include "engine/Time.hpp"
#include "game/Lifecycle.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <cstdlib>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Executed every frame.
 *
 * @param ren The renderer responsible for the window.
 */
void frame(SDL_Renderer *&ren) { UpdateObjects(ren); }

/**
 * @brief The main game loop, runs until an exit event is sensed, and QuitGame is set to true.
 *
 * @param ren The renderer responsible for the window. 
 */
void gameLoop(SDL_Renderer *&ren) {
    SDL_Event e;
    while (!QuitGame) {
        while (SDL_PollEvent(&e)) {
            HandleEvent(e);
        }
        SDL_RenderClear(ren);
        UpdateDeltaTime();
        frame(ren);
        SDL_RenderPresent(ren);
        // avoid windows thinking the window has crashed.
        SDL_Delay(1);
    }
}

/**
 * @brief Entry point of the program.
 *
 * @return Exit code
 */
int main() {
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *win;
    SDL_Renderer *ren;
    if (SDL_CreateWindowAndRenderer("", ScreenWidth, ScreenHeight,
                                    SDL_WINDOW_BORDERLESS, &win, &ren) == 0) {
        fprintf(stderr, "SDL_CreateWindowAndRenderer Error:%s\n",
                SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    InitializeGame();

    gameLoop(ren);

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return EXIT_SUCCESS;
}
