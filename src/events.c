#include "../include/maze.h"

/**
 * key_release_events - What key was released
 * @event: Event elemenet containing which key was released
 * @key_press: Struct containing significant keys to check if they were pressed
 */

void key_release_events(SDL_Event event, keys *key_press)
{
	switch (event.key.keysym.sym)
	{
		case SDLK_t:
		case SDLK_UP:
			key_press->up = 0;
			break;

		case SDLK_g:
		case SDLK_DOWN:
			key_press->down = 0;
			break;

		case SDLK_h:
		case SDLK_RIGHT:
			key_press->right = 0;
			break;

		case SDLK_f:
		case SDLK_LEFT:
			key_press->left = 0;
			break;

		default:
			break;
	}
}

/**
 * key_press_events - What key that was pressed down
 * @event: Event element containing which key was pressed
 * @key_press: Struct containing significant keys to check if they were pressed
 *
 * Return: If ESC is pressed - (1), otherwise - (0)
 */

int key_press_events(SDL_Event event, keys *key_press)
{
	if (event.key.keysym.scancode == 0x29)
		return (1);
	switch (event.key.keysym.sym)
	{
		case SDLK_t:
		case SDLK_UP:
			key_press->up = 1;
			break;

		case SDLK_g:
		case SDLK_DOWN:
			key_press->down = 1;
			break;

		case SDLK_h:
		case SDLK_RIGHT:
			key_press->right = 1;
			break;

		case SDLK_f:
		case SDLK_LEFT:
			key_press->left = 1;
			break;

		default:
			break;
	}
	return (0);
}

/**
 * keyboard_events - Listen for key presses
 * @key_press: Struct for up/down/left/right key presses
 *
 * Return: For standard events - (0),
 *		otherwise - (1) for exit events
 */

int keyboard_events(keys *key_press)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return (1);

		case SDL_KEYDOWN:
			if (key_press_events(event, key_press))
				return (1);
			break;

		case SDL_KEYUP:
			key_release_events(event, key_press);
			break;

		default:
			break;
		}
	}
	return (0);
}
