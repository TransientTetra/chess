#include "headers.h"

//todo:


int main(int argc, char const *argv[])
{
	short int quit = 0;
	SDL_Event event;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *scrtex = NULL;
	SDL_Surface *screen = NULL;
	SDL_Surface *pawn_white = NULL, *pawn_black = NULL;
	SDL_Surface *rook_white = NULL, *rook_black = NULL;
	SDL_Surface *knight_white = NULL, *knight_black = NULL;
	SDL_Surface *queen_white = NULL, *queen_black = NULL;
	SDL_Surface *king_white = NULL, *king_black = NULL;
	SDL_Surface *bishop_white = NULL, *bishop_black = NULL;

	if (init(&window, &renderer, &scrtex, &screen) == 1)
	{
		return 1;
	}

	if (load_graphics(
		&pawn_white, "./art/pawn_white.bmp",
		&pawn_black, "./art/pawn_black.bmp",
		&rook_white, "./art/rook_white.bmp",
		&rook_black, "./art/rook_black.bmp",
		&knight_white, "./art/knight_white.bmp",
		&knight_black, "./art/knight_black.bmp", 
		&queen_white, "./art/queen_white.bmp",
		&queen_black, "./art/queen_black.bmp",
		&king_white, "./art/king_white.bmp",
		&king_black, "./art/king_black.bmp",
		&bishop_white, "./art/bishop_white.bmp",
		&bishop_black, "./art/bishop_black.bmp") == 1)
	{
		SDL_FreeSurface(screen);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	while (quit == 0)
	{
		// SDL_BlitSurface(knight_white, NULL, screen, NULL);
		// SDL_BlitSurface(rook_white, NULL, screen, NULL);
		// SDL_BlitSurface(pawn_white, NULL, screen, NULL);
		SDL_BlitSurface(queen_white, NULL, screen, NULL);
		// SDL_BlitSurface(king_white, NULL, screen, NULL);
		// SDL_BlitSurface(bishop_white, NULL, screen, NULL);
		// SDL_BlitSurface(pawn_white, NULL, screen, NULL);
		// SDL_BlitSurface(pawn_white, NULL, screen, NULL);
		// SDL_BlitSurface(pawn_white, NULL, screen, NULL);
		// SDL_BlitSurface(pawn_white, NULL, screen, NULL);
		SDL_UpdateWindowSurface(window);

		while(SDL_PollEvent(&event) != 0)
		{
			switch(event.type)
			{
				case SDL_QUIT:
					quit = 1;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{

					}
			}
		}
	}

	SDL_FreeSurface(pawn_white);
	SDL_FreeSurface(pawn_black);
	SDL_FreeSurface(rook_white);
	SDL_FreeSurface(rook_black);
	SDL_FreeSurface(knight_white);
	SDL_FreeSurface(knight_black);
	SDL_FreeSurface(queen_white);
	SDL_FreeSurface(queen_black);
	SDL_FreeSurface(king_white);
	SDL_FreeSurface(king_black);
	SDL_FreeSurface(bishop_white);
	SDL_FreeSurface(bishop_black);
	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}