#include "main.h"
#include <stdlib.h>
#include "SDL3/SDL.h"
#include "browser.h"

int realloc_bw_regions(BrowserWindowRegions *regions, const size_t regions_count) {
    regions->regions_count = regions_count;
    BrowserWindowRegion *new = realloc(regions->regions, regions->regions_count * sizeof(*regions->regions));
    if (new == nullptr) return EXIT_FAILURE;
    regions->regions = new;
    return EXIT_SUCCESS;
}

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL not initialized!\n  %s", SDL_GetError());
        return 1;
    }

    WindowProps *window_props = malloc(sizeof(WindowProps));
    window_props->width = 1280;
    window_props->height = 720;

    SDL_Window *window = SDL_CreateWindow("Fazed Edge", window_props->width, window_props->height, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
    SDL_Event event;
    BrowserWindowRegions *window_regions = malloc(sizeof(BrowserWindowRegions));
    browser_init(window_props, window_regions);

    bool keep_running = true;
    while (keep_running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                keep_running = false;
            }
        }

        SDL_RenderClear(renderer);
        browser_render(window_props, window_regions);
    }

    free(window_regions);
    free(window_props);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
