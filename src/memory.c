#include "../include/maze.h"

/**
 * free_memory - Frees and closes all manually created memory
 * @instance: SDL_Instance containing window and renderer
 * @map: 2D array representing map of play space
 * @map_h: Height of the map
 */

void free_memory(SDL_Instance instance, char **map, size_t map_h)
{
	free_map(map, map_h);
	close_SDL(instance);
}


/**
 * free_map - Frees the map 2D array
 * @map: 2D array representing the map of the play space
 * @map_h: Height of the map
 */

void free_map(char **map, size_t map_h)
{
	size_t index = 0;

	while (index < map_h)
	{
		free(map[index]);
		index++;
	}
}


/**
 * close_SDL - Closes and cleans up the SDL window & renderer
 * @instance: Struct containing window & renderer
 */

void close_SDL(SDL_Instance instance)
{
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
}
