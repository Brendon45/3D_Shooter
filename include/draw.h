#ifndef DRAW_H
#define DRAW_H

void draw(SDL_Instance, char **, double_s, double_s, double_s);
void draw_walls(char **, double_s, SDL_Instance, double_s, double_s);
void select_color(SDL_Instance, char **, int_s, int);
void draw_background(SDL_Instance);

#endif  /* DRAW_H */
