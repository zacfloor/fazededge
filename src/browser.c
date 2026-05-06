#include "browser.h"

#define REGIONS_COUNT 1

void browser_init(const WindowProps *props, BrowserWindowRegions *regions) {
    realloc_bw_regions(regions, REGIONS_COUNT);

    const BrowserWindowRegion region = {0, 0, props->width, props->height};
    regions->regions[0] = region;
}

void browser_render(const WindowProps *props, BrowserWindowRegions *regions) {
}
