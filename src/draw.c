#include "../include/maze.h"

/**
 * draw - Runs necessary draw functions to create visuals
 * @instance: SDL_Instance containing game window & renderer
 * @map: 2D array representing the play space, wall & players
 * @play: x/y position of the player
 * @direction: Direction vector the player is facing
 * @plane: The projection plane
 */

void draw(SDL_Instance instance, char **map, double_s play,
		  double_s direction, double_s plane)
{
	draw_background(instance);
	draw_walls(map, play, instance, direction, plane);
	SDL_RenderPresent(instance.renderer);
}


/**
 * draw_background - Drawing the sky and floor
 * @instance: SDL_Instance containing the window and renderer objects
 */

void draw_background(SDL_Instance instance)
{
	size_t x;

	for (x = 0; x <= SCREEN_WIDTH; x++)
	{
		SKY_COLOR_BLUE(instance);
		SDL_RenderDrawLine(instance.renderer, x, 0, x, SCREEN_HEIGHT / 2);

		FLOOR_COLOR_GRAY(instance);
		SDL_RenderDrawLine(instance.renderer, x, SCREEN_HEIGHT / 2, x,
																SCREEN_HEIGHT);
	}
}


/**
 * draw_walls - Use Raycasting to draw the walls of the maze
 * @map: A 2D array representing the locations of walls and the player
 * @play: The player's current position
 * @instance: An SDL_Instance that contains the window and renderer objects
 * @dir: The direction vector of the player
 * @plane: The x/y values of the camera/projection plane
 */

void draw_walls(char **map, double_s play, SDL_Instance instance,
				double_s dir, double_s plane)
{
	double_s ray_position, ray_direction, dist_side, dist_del;
	double wall_distance, camera_x;
	int_s coordinate, step;
	int wall_height, wall_start, wall_end, screen_x, hit_side;

	for (screen_x = 0; screen_x < SCREEN_WIDTH; screen_x++)
	{
		hit_side = 0;
		camera_x = 2 * screen_x / (double)SCREEN_WIDTH - 1;

		ray_position.x = play.x;
		ray_position.y = play.y;

		ray_direction.x = dir.x + plane.x * camera_x;
		ray_direction.y = dir.y + plane.y * camera_x;

		coordinate.x = (int)ray_position.x;
		coordinate.y = (int)ray_position.y;

		dist_del.x = sqrt(1 + (ray_direction.y * ray_direction.y) / (ray_direction.x * ray_direction.x));
		dist_del.y = sqrt(1 + (ray_direction.x * ray_direction.x) / (ray_direction.y * ray_direction.y));

		raycast_direction(&step, &dist_side, ray_position, coordinate, dist_del, ray_direction);

		wall_distance = distance_from_wall(map, &dist_side, &coordinate, &step,
								  &dist_del, &hit_side, &ray_direction, &ray_position);

		wall_height = (int)(SCREEN_HEIGHT / wall_distance);
		wall_start = -wall_height / 2 + SCREEN_HEIGHT / 2;

		if (wall_start < 0)
			wall_start = 0;

		wall_end = wall_height / 2 + SCREEN_HEIGHT / 2;
		if (wall_end >= SCREEN_HEIGHT)
			wall_end = SCREEN_HEIGHT - 1;

		choose_color(instance, map, coordinate, hit_side);
		SDL_RenderDrawLine(instance.renderer, screen_x, wall_start, screen_x,
																	wall_end);
	}
}


/**
 * choose_color - Choose the color to draw for the wall
 * @instance: An SDL_Instance containing the renderer to draw with
 * @map: 2D array representing the map of the maze
 * @coordinate: coordinateinates on the map
 * @hit_side: Is the wall N/S or E/W
 */

void choose_color(SDL_Instance instance, char **map, int_s coordinate, int hit_side)
{
		switch (map[coordinate.x][coordinate.y])
		{
		case '1':
			/* Dark Green walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0x55, 0x6B, 0x2F, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0x80, 0x80, 0, 0xFF);
			break;
		case '2':
			/* Dark Yellow Walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0xCC, 0xCC, 0, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0x66, 0x66, 0, 0xFF);
			break;
		case '3':
			/* Red Brick color Walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0xB7, 0x32, 0x39, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0x92, 0x28, 0x2E, 0xFF);
			break;
		case '4':
			/* Brown Walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0x7B, 0x3F, 0, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0x5C, 0x40, 0x33, 0xFF);
			break;
		default:
			/* White Walls */
			if (hit_side == 0)
				SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			else
				SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0xFF);
			break;
		}
}
