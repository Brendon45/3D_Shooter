#ifndef MEMORY_H
#define MEMORY_H

void free_memory(SDL_Instance, char **, size_t);
void free_map(char **, size_t);
void close_SDL(SDL_Instance);

#endif  /* MEMORY_H */

