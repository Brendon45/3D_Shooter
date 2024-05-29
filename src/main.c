#include <SDL2/SDL.h>

/**
 * main - Entry point
 * @argc: Number of arguments passed to the program
 * @argv: Pointer to string arguments passed to the program
 *
 * Return: On success (0),
 *			else failure status if failed.
 */

int main(void)
{
	/* Drawing the window */
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	/* Initialize SDL, width and height */
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(640 * 4, 480 * 4, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 4, 4);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	/* Drawing on the window and centering it */
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(renderer, 640/2, 480/2);

	/* Make sure the window doesn't close immediately */
	SDL_RenderPresent(renderer);
	SDL_Delay(10000);

	return (0);
}
