#ifndef MACROS_H
#define MACROS_H

/* Screen */
#define SCREEN_HEIGHT 768
#define SCREEN_WIDTH 1024

/* Map */
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/* Booleans */
#define TRUE 1
#define FALSE 0

/* Colors */
#define REND_COLOR_WHITE(x) SDL_SetRenderDrawColor(x, 255, 255, 255, 255)
#define REND_COLOR_BLACK(x) SDL_SetRenderDrawColor(x, 0, 0, 0, 255)
#define REND_COLOR_YELLOW(x) SDL_SetRenderDrawColor(x, 255, 255, 0, 255)
#define REND_COLOR_GREEN(x) SDL_SetRenderDrawColor(x, 0, 255, 0, 255)
#define REND_COLOR_BLUE(x) SDL_SetRenderDrawColor(x, 0, 0, 255, 255)
#define REND_COLOR(x, r, g, b, a) SDL_SetRenderDrawColor(x, r, g, b, a)

#endif  /* MACROS_H */
