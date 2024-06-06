#include "../include/maze.h"

/**
 * rotate - Rotates the camera left/right
 * @plane: Projection plane
 * @direction: Players direction vector
 * @rotation_direction: Rotation direction,
 *						(-1) for right, (1) for left
 */

void rotate(double_s *plane, double_s *direction, int rotation_direction)
{
	double rotate_speed, old_direction_x, old_plane_x;

	rotate_speed = 0.03 * rotation_direction;
	old_direction_x = direction->x;
	direction->x = direction->x * cos(rotate_speed) - direction->y * sin(rotate_speed);
	direction->y = old_direction_x * sin(rotate_speed) + direction->y * cos(rotate_speed);
	old_plane_x = plane->x;
	plane->x = plane->x * cos(rotate_speed) - plane->y * sin(rotate_speed);
	plane->y = old_plane_x * sin(rotate_speed) + plane->y * cos(rotate_speed);
}


/**
 * movement - Moving around the map
 * @key_press: Keyboard key pressed
 * @plane: x/y direction vector of the projection plane
 * @direction: x/y of the direction vector the player is looking
 * @play: x/y starting positions of the player
 * @map: The map of the level
 */

void movement(keys key_press, double_s *plane, double_s *direction,
			  double_s *play, char **map)
{
	double move_speed = 0.07;

	if (key_press.right)
	{
		rotate(plane, direction, -1);
	}
	if (key_press.left)
		rotate(plane, direction, 1);
	if (key_press.up)
	{
		if (map[(int)(play->x + direction->x * move_speed)][(int)play->y] == '0')
			play->x += direction->x * move_speed;

		if (map[(int)play->x][(int)(play->y + direction->y * move_speed)] == '0')
			play->y += direction->y * move_speed;
	}
	if (key_press.down)
	{
		if (map[(int)(play->x - direction->x * move_speed)][(int)play->y] == '0')
			play->x -= direction->x * move_speed;

		if (map[(int)play->x][(int)(play->y - direction->y * move_speed)] == '0')
			play->y -= direction->y * move_speed;
	}
}
