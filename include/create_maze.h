#ifndef CREATE_MAZE_H
#define CREATE_MAZE_H

char **create_map(char *, double_s *, int_s *, size_t *);
void plot_grid_points(char **, double_s *, int_s *, size_t, size_t, char *,
		      int *);
size_t get_line_count(char *);
size_t get_character_count(char *);

#endif  /* CREATE_MAZE_H */
