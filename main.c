#include "headers.h"

//todo:

int main(int argc, char const *argv[])
{
	SDL_Window *window = NULL;
	SDL_Surface *screen = NULL;


	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	screen = SDL_GetWindowSurface(window);
	SDL_ShowCursor(SDL_DISABLE);

	for (int i = 0; i < 100; ++i)
	{
		if (i % 2)
		{
			SDL_FillRect(screen, NULL, GREEN);
		}
		else
		{
			SDL_FillRect(screen, NULL, RED);
		}
		SDL_UpdateWindowSurface(window);
		SDL_Delay(100);
	}

	SDL_DestroyWindow(window);
	SDL_FreeSurface(screen);
	SDL_Quit();

	return 0;
}