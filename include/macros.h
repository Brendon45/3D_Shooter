#ifndef MACROS_H
#define MACROS_H

/* Screen */
#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

/* Map */
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/* Booleans */
#define TRUE 1
#define FALSE 0

/* Colors: draw.c */
#define SKY_COLOR_BLUE(instance) SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0x88, 0xFF);
#define FLOOR_COLOR_GRAY(instance) SDL_SetRenderDrawColor(instance.renderer, 0x88, 0x88, 0x88, 0xFF);

	/* Wall color options */
#

#endif /* MACROS_H */
