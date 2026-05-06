#pragma once
#include "SDL3/SDL_rect.h"

typedef struct {
    int width, height;
} WindowProps;

typedef SDL_Rect BrowserWindowRegion;

typedef struct {
    BrowserWindowRegion *regions;
    size_t regions_count;
} BrowserWindowRegions;

int realloc_bw_regions(BrowserWindowRegions *regions, size_t regions_count);
