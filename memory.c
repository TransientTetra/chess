#include "headers.h"

//initializes sdl, creates window and screen
int init(SDL_Window **window, SDL_Renderer **renderer, SDL_Texture **scrtex, SDL_Surface **screen)
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

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if (*renderer == NULL)
	{
		fprintf(stderr, "Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	*screen = SDL_GetWindowSurface(*window);
	SDL_ShowCursor(SDL_DISABLE);
	return 0;
}

//loads bitmaps to sdl surfaces
int load_graphics(
	SDL_Surface **pawn_white, const char *pawn_white_location,
	SDL_Surface **pawn_black, const char *pawn_black_location,
	SDL_Surface **rook_white, const char *rook_white_location,
	SDL_Surface **rook_black, const char *rook_black_location,
	SDL_Surface **knight_white, const char *knight_white_location,
	SDL_Surface **knight_black, const char *knight_black_location,
	SDL_Surface **queen_white, const char *queen_white_location,
	SDL_Surface **queen_black, const char *queen_black_location,
	SDL_Surface **king_white, const char *king_white_location,
	SDL_Surface **king_black, const char *king_black_location,
	SDL_Surface **bishop_white, const char *bishop_white_location,
	SDL_Surface **bishop_black, const char *bishop_black_location)
{
	*pawn_white = SDL_LoadBMP(pawn_white_location);
	if (*pawn_white == NULL)
	{
		fprintf(stderr, "couldn't load pawn_white\n");
		return 1;
	}
	*pawn_black = SDL_LoadBMP(pawn_black_location);
	if (*pawn_black == NULL)
	{
		fprintf(stderr, "couldn't load pawn_black\n");
		SDL_FreeSurface(*pawn_white);
		return 1;
	}
	*rook_white = SDL_LoadBMP(rook_white_location);
	if (*rook_white == NULL)
	{
		fprintf(stderr, "couldn't load rook_white\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		return 1;
	}
	*rook_black = SDL_LoadBMP(rook_black_location);
	if (*rook_black == NULL)
	{
		fprintf(stderr, "couldn't load rook_black\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		SDL_FreeSurface(*rook_white);
		return 1;
	}
	*knight_white = SDL_LoadBMP(knight_white_location);
	if (*knight_white == NULL)
	{
		fprintf(stderr, "couldn't load knight_white\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		SDL_FreeSurface(*rook_white);
		SDL_FreeSurface(*rook_black);
		return 1;
	}
	*knight_black = SDL_LoadBMP(knight_black_location);
	if (*knight_black == NULL)
	{
		fprintf(stderr, "couldn't load knight_black\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		SDL_FreeSurface(*rook_white);
		SDL_FreeSurface(*rook_black);
		SDL_FreeSurface(*knight_white);
		return 1;
	}
	*queen_white = SDL_LoadBMP(queen_white_location);
	if (*queen_white == NULL)
	{
		fprintf(stderr, "couldn't load queen_white\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		SDL_FreeSurface(*rook_white);
		SDL_FreeSurface(*rook_black);
		SDL_FreeSurface(*knight_white);
		SDL_FreeSurface(*knight_black);
		return 1;
	}
	*queen_black = SDL_LoadBMP(queen_black_location);
	if (*queen_black == NULL)
	{
		fprintf(stderr, "couldn't load queen_black\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		SDL_FreeSurface(*rook_white);
		SDL_FreeSurface(*rook_black);
		SDL_FreeSurface(*knight_white);
		SDL_FreeSurface(*knight_black);
		SDL_FreeSurface(*queen_white);
		return 1;
	}
	*king_white = SDL_LoadBMP(king_white_location);
	if (*king_white == NULL)
	{
		fprintf(stderr, "couldn't load king_white\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		SDL_FreeSurface(*rook_white);
		SDL_FreeSurface(*rook_black);
		SDL_FreeSurface(*knight_white);
		SDL_FreeSurface(*knight_black);
		SDL_FreeSurface(*queen_white);
		SDL_FreeSurface(*queen_black);
		return 1;
	}
	*king_black = SDL_LoadBMP(king_black_location);
	if (*king_black == NULL)
	{
		fprintf(stderr, "couldn't load king_black\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		SDL_FreeSurface(*rook_white);
		SDL_FreeSurface(*rook_black);
		SDL_FreeSurface(*knight_white);
		SDL_FreeSurface(*knight_black);
		SDL_FreeSurface(*queen_white);
		SDL_FreeSurface(*queen_black);
		SDL_FreeSurface(*king_white);
		return 1;
	}
	*bishop_white = SDL_LoadBMP(bishop_white_location);
	if (*bishop_white == NULL)
	{
		fprintf(stderr, "couldn't load bishop_white\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		SDL_FreeSurface(*rook_white);
		SDL_FreeSurface(*rook_black);
		SDL_FreeSurface(*knight_white);
		SDL_FreeSurface(*knight_black);
		SDL_FreeSurface(*queen_white);
		SDL_FreeSurface(*queen_black);
		SDL_FreeSurface(*king_white);
		SDL_FreeSurface(*king_black);
		return 1;
	}
	*bishop_black = SDL_LoadBMP(bishop_black_location);
	if (*bishop_black == NULL)
	{
		fprintf(stderr, "couldn't load bishop_black\n");
		SDL_FreeSurface(*pawn_white);
		SDL_FreeSurface(*pawn_black);
		SDL_FreeSurface(*rook_white);
		SDL_FreeSurface(*rook_black);
		SDL_FreeSurface(*knight_white);
		SDL_FreeSurface(*knight_black);
		SDL_FreeSurface(*queen_white);
		SDL_FreeSurface(*queen_black);
		SDL_FreeSurface(*king_white);
		SDL_FreeSurface(*king_black);
		SDL_FreeSurface(*bishop_white);
		return 1;
	}
	return 0;
}