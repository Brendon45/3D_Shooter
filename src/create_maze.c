#include "../include/maze.h"

/**
 * line_count - Counting line numbers in the file
 * @file_string: Path to file to evaluate
 *
 * Return: Number of lines, otherwise - (0) it failed
 */

size_t line_count(char *file_string)
{
	FILE *maze_file;
	char *line;
	ssize_t read = 0;
	size_t lines, line_len;

	maze_file = fopen(file_string, "r");

	if (maze_file == NULL)
	{
		printf("File doesn't exist\n");
		return (0);
	}

	lines = 0;
	read = getline(&line, &line_len, maze_file);

	if (read == -1)
	{
		return (0);
	}
	lines++;

	while (read != -1)
	{
		read = getline(&line, &line_len, maze_file);
		lines++;
	}
	fclose(maze_file);
	return (lines);
}


/**
 * character_count - Counts characters in a string
 * @line: String to be evaluated
 *
 * Return: Value of charCount
 */

size_t character_count(char *line)
{
	size_t charCount = 0;

	while (line[charCount] != '\0')
	{
		charCount++;
	}
	return (charCount);
}


/**
 * plot_grid_points - Plots the specific points in the maze
 * @maze: 2D array representing the grid of the map
 * @play: Player's x and y positions
 * @win: x/y coordinates of the win square
 * @current_character: Current character in the line being read
 * @maze_line: Line being created in the maze currently
 * @line: Line being read from the file
 * @found_win: Previously the win square in the maze found
 */

void plot_grid_points(char **maze, double_s *play, int_s *win,
		size_t current_character, size_t maze_line, char *line, int *found_win)
{
	if (line[current_character] == 'p')
	{
		play->y = current_character;
		play->x = maze_line;
		maze[maze_line][current_character] = '0';
	}
	else if (line[current_character] == 'w')
	{
		*found_win = 1;
		win->y = current_character;
		win->x = maze_line;
		maze[maze_line][current_character] = '0';
	}
	else
	{
		if (line[current_character] == '0' && *found_win == 0)
		{
			win->y = current_character;
			win->x = maze_line;
		}
		maze[maze_line][current_character] = line[current_character];
	}
}


/**
 * create_map - Creates 2D array for the map of the maze
 * @file_string: File containing the representation of the map
 * @play: Player's x and y positions
 * @win: x/y coordinates of the winning space
 * @map_h: Height of the 2D array representing the play space
 *
 * Return: Character ** to a representation of the map, otherwise - NULL
 */

char **create_map(char *file_string, double_s *play, int_s *win, size_t *map_h)
{
	FILE *maze_file;
	char **maze, *line = NULL;
	ssize_t read = 0;
	size_t lineCount, maze_line, charCount, current_character, buffer_size;
	int found_win = 0;

	found_win = 0;
	maze_line = 0;
	lineCount = line_count(file_string);
	*map_h = lineCount;

	if (lineCount == 0)
		return (NULL);

	maze = malloc(sizeof(int *) * lineCount);
	if (maze == NULL)
		return (NULL);

	maze_file = fopen(file_string, "r");
	if (maze_file == NULL)
		return (NULL);

	read = getline(&line, &buffer_size, maze_file);
	while (read != -1)
	{
		charCount = character_count(line);
		maze[maze_line] = malloc(sizeof(char) * charCount + 1);

		if (maze == NULL)
			return (NULL);

		for (current_character = 0; current_character < charCount; current_character++)
		{
			plot_grid_points(maze, play, win, current_character, maze_line, line, &found_win);
		}
		maze_line++;
		read = getline(&line, &buffer_size, maze_file);
	}
	fclose(maze_file);
	free(line);
	return (maze);
}
