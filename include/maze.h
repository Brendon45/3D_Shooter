#ifndef MAZE_H
#define MAZE_H

/* Libraries */
#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Include headers */
#include "create_maze.h"
#include "draw.h"
#include "events.h"
#include "macros.h"
#include "memory.h"
#include "structures.h"

int init_instance(SDL_Instance *);


level *build_world_from_args(int, char **);


void rotate(double_s *, double_s *, int);
void movement(keys, double_s *, double_s *, double_s *, char **);


void print_win(void);
int check_win(double_s, int_s, int *);


double get_wall_dist(char **, double_s *, int_s *, int_s *, double_s *, int *,
		     double_s *, double_s *);
void check_ray_dir(int_s *, double_s *, double_s, int_s, double_s, double_s);

#endif  /* MAZE_H */
