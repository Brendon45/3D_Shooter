#include "../include/maze.h"

/**
 * create_world_from_args - Create the game depending of the map(s) passed
 * @number_of_levels: Numbers of files passed
 * @level_files: Array with the name of the files passed
 *
 * Return: A list with the path of the files passed, otherwise - NULL
 */

level *create_world_from_args(int number_of_levels, char *level_files[])
{
	level stage = { NULL, 0, {0, 0}, {2, 2}, {-1, 0}, {0, 0.5} };
	level *levels;
	int index, lvl;

	levels = malloc(sizeof(level) * (number_of_levels - 1));
	if (levels == NULL)
		return (NULL);
	lvl = 0;

	for (index = 1; index < number_of_levels; index++)
	{
		stage.map = create_map(level_files[index], &stage.play, &stage.win,
																&stage.height);
		if (stage.map == NULL)
			return (NULL);

		levels[lvl] = stage;
		lvl++;
	}
	return (levels);
}
