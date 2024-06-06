#include "../include/maze.h"

/**
 * main - Maze Game
 * @argc: Number of arguments
 * @argv: Arguments passed to the program
 *
 * Return: On success - (0),
 *			otherwise - (1)
 */

int main(int argc, char *argv[])
{
	SDL_Instance instance;
	level *levels;
	int lvl, win_value, num_of_levels;

	/* Initialize all values to 0 */
	keys key_press = {0, 0, 0, 0};

	lvl = win_value = 0;

	/* argc = levels included when running game */
	num_of_levels = argc;

	if (num_of_levels < 2)
		return (1);

	/* Generating a map from levels entered */
	levels = create_world_from_args(argc, argv);

	if (levels == NULL)
		return (1);

	/* Initialize SDL2, Window & renderer */
	if (initialize(&instance) != 0)
		return (1);

	lvl = 0;
	while (1)
	{
		if (keyboard_events(&key_press))  /* Pass key_press instance */
		{
			free_memory(instance, levels[lvl].map, levels[lvl].height);
			break;
		}
		movement(key_press, &levels[lvl].plane, &levels[lvl].dir, &levels[lvl].play,
			 levels[lvl].map);
		if (winning(levels[lvl].play, levels[lvl].win, &win_value))
		{
			free_map(levels[lvl].map, levels[lvl].height);
			lvl++;
			if (lvl == argc - 1)
				break;
			win_value = 0;
		}
		draw(instance, levels[lvl].map, levels[lvl].play, levels[lvl].dir,
		     levels[lvl].plane);
	}
	free_memory(instance, levels[lvl].map, levels[lvl].height);

	/* close_SDL(instance); */
	if (win_value)
		you_won();
	return (0);
}
