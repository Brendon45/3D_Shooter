#include "../include/maze.h"

/**
 * you_won - Displays a win message when player finishes the game
 */

void you_won(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("     \\  /  ___    |     |\n");
	printf("      \\/  /  \\   |     |\n");
	printf("       /   |    |  |     |\n");
	printf("      /    \\__/   \\___/\n\n");
	printf("\\      /\\      / ------- |\\   |\n");
	printf(" \\    /  \\    /  |     | | \\  |\n");
	printf("  \\  /    \\  /   |     | |  \\ |\n");
	printf("   \\/      \\/    ------- |   \\|\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
}


/**
 * winning - Player has found the win spot in the maze
 * @play: x/y coordinates of the payer
 * @win: x/y coordinates of the win space
 * @win_value: If the player has found the win space or not
 *
 * Return: If player found win space - (1),
 *			otherwise - (0)
 */

int winning(double_s play, int_s win, int *win_value)
{
	if ((int) play.x == win.x && (int) play.y == win.y)
	{
		*win_value = 1;
		return (1);
	}
	return (0);
}
