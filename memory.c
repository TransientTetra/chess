#include "headers.h"

//initializes sdl, creates window and screen
int init(SDL_Window **window, SDL_Surface **screen)
{	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	*window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (*window == NULL)
	{
		fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	*screen = SDL_GetWindowSurface(*window);
	if (*screen == NULL)
	{
		fprintf(stderr, "Screen could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(*window);
		return 1;
	}

	SDL_ShowCursor(SDL_DISABLE);
	return 0;
}

//loads bitmaps for white and black pieces
int load_graphics(
	SDL_Surface **white_pieces, const char *white_location,
	SDL_Surface **black_pieces, const char *black_location)
{
	*white_pieces = SDL_LoadBMP(white_location);
	if (*white_pieces == NULL)
	{
		fprintf(stderr, "couldn't load white_pieces\n");
		return 1;
	}
	*black_pieces = SDL_LoadBMP(black_location);
	if (*black_pieces == NULL)
	{
		fprintf(stderr, "couldn't load black_pieces\n");
		SDL_FreeSurface(*white_pieces);
		return 1;
	}
	return 0;
}