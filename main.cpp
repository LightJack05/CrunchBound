#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void frame(SDL_Renderer *&ren, SDL_Event &e, bool &quit) {
        SDL_SetRenderDrawColor(ren, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_FRect *rect = new SDL_FRect();
        rect->h = 300;
        rect->w = 400;
        rect->x = 500;
        rect->y = 200;
        SDL_RenderFillRect(ren, rect);

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
}

void gameLoop(SDL_Renderer *&ren, SDL_Event &e, bool &quit) {
        while (!quit) {
                while (SDL_PollEvent(&e)) {
                        if (e.type == SDL_EVENT_QUIT) {
                                quit = true;
                        }
                }
                SDL_RenderClear(ren);
                frame(ren, e, quit);
                SDL_RenderPresent(ren);
                // avoid windows thinking the window has crashed.
                SDL_Delay(100);
        }
}

int main() {
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
                fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
                return EXIT_FAILURE;
        }

        SDL_Window *win;
        SDL_Renderer *ren;
        if (SDL_CreateWindowAndRenderer("Hello World!", 2000, 1200,
                                        SDL_WINDOW_RESIZABLE, &win,
                                        &ren) == 0) {
                fprintf(stderr, "SDL_CreateWindowAndRenderer Error: %s\n",
                        SDL_GetError());
                SDL_Quit();
                return EXIT_FAILURE;
        }

        SDL_Event e;
        bool quit = false;
        Uint32 startTime = SDL_GetTicks();
        gameLoop(ren, e, quit);

        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return EXIT_SUCCESS;
}
