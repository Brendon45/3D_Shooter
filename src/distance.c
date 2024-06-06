#include "../include/maze.h"

/**
 * raycast_direction - Direction is the ray being casted
 * @step: Direction to move
 * @dist_side: Distance to next square on the grid
 * @ray_position: Start position of the ray being cast
 * @coordinate: Coordinates on the grid
 * @dist_del: Difference in distance between two sides of a grid
 * @ray_direction: Ray's vector direction
 */

void raycast_direction(int_s *step, double_s *dist_side, double_s ray_position,
				   int_s coordinate, double_s dist_del, double_s ray_direction)
{
	if (ray_direction.x < 0)
	{
		step->x = -1;
		dist_side->x = (ray_position.x - coordinate.x) * dist_del.x;
	}
	else
	{
		step->x = 1;
		dist_side->x = (coordinate.x + 1.0 - ray_position.x) * dist_del.x;
	}
	if (ray_direction.y < 0)
	{
		step->y = -1;
		dist_side->y = (ray_position.y - coordinate.y) * dist_del.y;
	}
	else
	{
		step->y = 1;
		dist_side->y = (coordinate.y + 1 - ray_position.y) * dist_del.y;
	}
}

/**
 * distance_from_wall - Distance from the player to the wall
 * @map: 2D Array representing the map of the maze
 * @dist_side: x and y values of the distance to the next side of the map grid
 * @coordinate: x and y coordinates of the player in the map
 * @step: direction player will move in on the x/y axes
 * @dist_del: The x/y change between two sides of the map grid
 * @hit_side: Hit North/South vs East/West wall
 * @ray_direction: Direction of the ray vector from the player
 * @ray_position: X/Y coordinates of the ray
 *
 * Return: Distance from player to the wall
 */

double distance_from_wall(char **map, double_s *dist_side, int_s *coordinate,
					 int_s *step, double_s *dist_del, int *hit_side,
					 double_s *ray_direction, double_s *ray_position)
{
	double wall_distance;
	int hit_wall = 0;

	while (hit_wall == 0)
	{
		if (dist_side->x < dist_side->y)
		{
			dist_side->x += dist_del->x;
			coordinate->x += step->x;
			*hit_side = 0;
		}
		else
		{
			dist_side->y += dist_del->y;
			coordinate->y += step->y;
			*hit_side = 1;
		}
		if (map[coordinate->x][coordinate->y] > '0')
			hit_wall = 1;
	}
	if (*hit_side == 0)
		wall_distance = (coordinate->x - ray_position->x + (1 - step->x) / 2) / ray_direction->x;
	else
		wall_distance = (coordinate->y - ray_position->y + (1 - step->y) / 2) / ray_direction->y;
	return (wall_distance);
}
