#include "engine/EngineState.hpp"
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
    // Clear the GameObjects vector, so the smart pointers delete themselves.
    GameObjects.clear();
    // Clear the GameManager, so it deletes itself.
    GameManager = nullptr;

    // Destroy the renderer and window
    SDL_DestroyRenderer(ren);
    ren = nullptr;
    GlobalRenderer = nullptr;
    SDL_DestroyWindow(win);
    win = nullptr;

    // Quit the libraries and free any resources.
    SDL_Quit();
    TTF_Quit();
}

/**
 * @brief Executed every frame.
 */
void Frame() { RunFrameActions(); }

/**
 * @brief The main game loop, runs until QuitGame is set to true.
 */
void GameLoop() {
    // Run in a loop until the game exits
    SDL_Event e;
    while (!QuitGame) {
        // Get an event if there is one, and pass it to the handler
        while (SDL_PollEvent(&e)) {
            HandleEvent(e);
        }
        // Update the DeltaTime variables, to make sure the game runs at the
        // same speed regardless of hardware and scheduling
        UpdateDeltaTime();
        // Set the background color before clearing the renderer, to reset it to the correct color.
        SDL_SetRenderDrawColor(GlobalRenderer, WindowBackgroundColor.r,
                               WindowBackgroundColor.g, WindowBackgroundColor.b,
                               WindowBackgroundColor.a);
        // Clear the screen
        SDL_RenderClear(GlobalRenderer);
        // Run the frame actions
        Frame();
        // Render any objects that have been passed to SDL
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
    // Initialize SDL and SDL_TTF
    // On failure, deinit and exit
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        CleanupBeforeExit(win, ren);
        return EXIT_FAILURE;
    }

    if (!TTF_Init()) {
        CleanupBeforeExit(win, ren);
        return EXIT_FAILURE;
    }

    // Create a window and renderer, and write their pointers into the local
    // pointer variables
    if (SDL_CreateWindowAndRenderer("", ScreenWidth, ScreenHeight,
                                    SDL_WINDOW_BORDERLESS, &win, &ren) == 0) {
        CleanupBeforeExit(win, ren);
        return EXIT_FAILURE;
    }
    // Set the renderer avaiable into the global scope.
    GlobalRenderer = ren;

    // Spawn initial objects and register them
    InitializeGame();

    // Enter the game loop that runs until the game exits
    GameLoop();

    // Before exiting, clean up any allocated resources, exit SDL, and clear the
    // pointers.
    CleanupBeforeExit(win, ren);
    return EXIT_SUCCESS;
}
