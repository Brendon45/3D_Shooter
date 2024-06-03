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


/* init_instance.c */
int init_instance(SDL_Instance *);

/* world_creation.c */
level *build_world_from_args(int, char **);

/* movement.c */
void rotate(double_s *, double_s *, int);
void movement(keys, double_s *, double_s *, double_s *, char **);

/* func_win.c */
void print_win(void);
int check_win(double_s, int_s, int *);

/* dist_checks.c */
double get_wall_dist(char **, double_s *, int_s *, int_s *, double_s *, int *,
		     double_s *, double_s *);
void check_ray_dir(int_s *, double_s *, double_s, int_s, double_s, double_s);

#endif  /* MAZE_H */
