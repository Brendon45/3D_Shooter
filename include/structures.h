#ifndef STRUCTURES_H
#define STRUCTURES_H

/**
 * struct SDL_Instance - Struct SDL renderer & window
 * @window: Window for displaying game render
 * @renderer: Rendering graphicss
 */

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;


/**
 * struct double_s - x/y values for doubles
 * @x: X value
 * @y: Y value
 */

typedef struct double_s
{
	double x;
	double y;
} double_s;


/**
 * struct int_s - x/y values of integers
 * @x: X value
 * @y: Y value
 */

typedef struct int_s
{
	int x;
	int y;
} int_s;


/**
 * struct keys - Key presses for event handlers
 * @up: On press (1), else (0)
 * @down: On press (1), else (0)
 * @right: On press (1), else (0)
 * @left: On press (1), else (0)
 */

typedef struct keys
{
	int up;
	int down;
	int right;
	int left;
} keys;


/**
 * struct level - Levels and starting values
 * @map: Level's map
 * @height: Map's height
 * @win: x/y coordinates of win space
 * @play: x/y starting position of player
 * @dir: x/y of direction vector the player is looking
 * @plane: x/y direction vector of projection plane
 */

typedef struct level
{
	char **map;
	size_t height;
	int_s win;
	double_s play;
	double_s dir;
	double_s plane;
} level;

#endif  /* STRUCTURES_H */
