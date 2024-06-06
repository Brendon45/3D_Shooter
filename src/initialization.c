#include "../include/maze.h"

/**
 * initialize - Initializing SDL2, window & renderer instances
 *
 * Return: On success - (0),
 *			otherwise - (1)
 */

int initialize(SDL_Instance *instance)
{
	instance->window = NULL;
	instance->renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Failed to initialize SDL. SDL_Error: %s\n", SDL_GetError());
		return (1);
	}

	/* Creating a window instance */
	instance->window = SDL_CreateWindow("3D Shooter: The maze", SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
											SCREEN_HEIGHT, 0);

	if (instance->window == NULL)
	{
		printf("Window not created SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* Creating Renderer instance linked to the Window */
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (instance->renderer == NULL)
	{  /* Destroying and cleaning up */
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(instance->window);
		SDL_Quit();
		return (1);
	}
	return (0);
}
