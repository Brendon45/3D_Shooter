#ifndef MAZE_H
#define MAZE_H

/* libraries */
#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Include headers */
#include "macros.h"

/**
 * struct SDL_Instance - SDL renderer & window
 * @window: Window to display game render
 * @renderer: Renders graphics
 */

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;


/**
 * struct double_s - x and y values for doubles
 * @x: X value
 * @y: Y value
 */

typedef struct double_s
{
	double x;
	double y;
} double_s;


/**
 * struct int_s - x and y values for integers
 * @x: X value
 * @y: Y value
 */

typedef struct int_s
{
	int x;
	int y;
} int_s;


/**
 * struct keys - Key presses from keyboard
 * @up: Pressed - (1), otherwise - (0)
 * @down: Pressed - (1), otherwise - (0)
 * @right: Pressed - (1), otherwise - (0)
 * @left: Pressed - (1), otherwise - (0)
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
 * @map: Map of level
 * @height: Height of the map
 * @win: x and y coordinates of win space
 * @play: x and y starting positions of the player
 * @dir: x and y of direction vector the player is looking
 * @plane: x and y direction vector of projection plane
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



/*------------------        FUNCTIONS            ----------------------------*/


/* creat_maze.c */
char **create_map(char *, double_s *, int_s *, size_t *);
void plot_grid_points(char **, double_s *, int_s *, size_t, size_t, char *,
																	int *);
size_t line_count(char *);
size_t character_count(char *);

/*-----------------------------------------------------------------------------*/

/* create_world.c */
level *create_world_from_args(int, char **);

/*-----------------------------------------------------------------------------*/

/* distance.c */
double distance_from_wall(char **, double_s *, int_s *, int_s *, double_s *,
												int *, double_s *, double_s *);
void raycast_direction(int_s *, double_s *, double_s, int_s, double_s, double_s);

/*-----------------------------------------------------------------------------*/

/* draw.c */
void draw(SDL_Instance, char **, double_s, double_s, double_s);
void draw_walls(char **, double_s, SDL_Instance, double_s, double_s);
void choose_color(SDL_Instance, char **, int_s, int);
void draw_background(SDL_Instance);

/*-----------------------------------------------------------------------------*/

/* events.c */
int keyboard_events(keys *);
void key_release_events(SDL_Event, keys *);
int key_press_events(SDL_Event, keys *);

/*-----------------------------------------------------------------------------*/

/* memory.c */
void free_memory(SDL_Instance, char **, size_t);
void free_map(char **, size_t);
void close_SDL(SDL_Instance);

/*-----------------------------------------------------------------------------*/

/* initialization.c */
int initialize(SDL_Instance *);

/*-----------------------------------------------------------------------------*/

/* movement.c */
void rotate(double_s *, double_s *, int);
void movement(keys, double_s *, double_s *, double_s *, char **);

/*-----------------------------------------------------------------------------*/

/* winning.c */
void you_won(void);
int winning(double_s, int_s, int *);


/**
 * More improvments to be added:
 * =============================
 *
 * score
 * health bar
 * enemies
 * shooting
 * power ups
 * secret doors, paths, keys, etc
 * nicer textures
 * make it rain!!!
 */

#endif  /* MAZE_H */
