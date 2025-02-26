#include "engine/Events.hpp"
#include "engine/GameManagement.hpp"
#include "engine/ObjectManagement.hpp"
#include "engine/Time.hpp"
#include "game/Lifecycle.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cstdlib>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Destroy all objects, the renderer and window, and quit SDL and TTF
 *
 * @param win The window of the application.
 * @param ren The renderer to destroy.
 */
inline void CleanupBeforeExit(SDL_Window *&win, SDL_Renderer *&ren) {
    GameObjects.clear();
    GameManager = nullptr;

    SDL_DestroyRenderer(ren);
    ren = nullptr;
    GlobalRenderer = nullptr;
    SDL_DestroyWindow(win);
    win = nullptr;

    SDL_Quit();
    TTF_Quit();
}

/**
 * @brief Executed every frame.
 */
void frame() { RunFrameActions(); }

/**
 * @brief The main game loop, runs until QuitGame is set to true.
 */
void gameLoop() {
    SDL_Event e;
    while (!QuitGame) {
        while (SDL_PollEvent(&e)) {
            HandleEvent(e);
        }
        UpdateDeltaTime();
        SDL_SetRenderDrawColor(GlobalRenderer, WindowBackgroundColor.r,
                               WindowBackgroundColor.g, WindowBackgroundColor.b,
                               WindowBackgroundColor.a);
        SDL_RenderClear(GlobalRenderer);
        frame();
        SDL_RenderPresent(GlobalRenderer);
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
    SDL_Window *win = nullptr;
    SDL_Renderer *ren = nullptr;
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        CleanupBeforeExit(win, ren);
        return EXIT_FAILURE;
    }

    if (!TTF_Init()) {
        CleanupBeforeExit(win, ren);
        return EXIT_FAILURE;
    }

    if (SDL_CreateWindowAndRenderer("", ScreenWidth, ScreenHeight,
                                    SDL_WINDOW_BORDERLESS, &win, &ren) == 0) {
        CleanupBeforeExit(win, ren);
        return EXIT_FAILURE;
    }
    GlobalRenderer = ren;

    InitializeGame();

    gameLoop();

    CleanupBeforeExit(win, ren);
    return EXIT_SUCCESS;
}
