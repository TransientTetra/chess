#include "headers.h"

//todo:


int main(int argc, char const *argv[])
{
	SDL_Window *window = NULL;
	SDL_Surface *screen = NULL;
	SDL_Surface *pawn_white = NULL, *pawn_black = NULL;
	SDL_Surface *rook_white = NULL, *rook_black = NULL;
	SDL_Surface *knight_white = NULL, *knight_black = NULL;
	SDL_Surface *queen_white = NULL, *queen_black = NULL;
	SDL_Surface *king_white = NULL, *king_black = NULL;
	SDL_Surface *bishop_white = NULL, *bishop_black = NULL;

	if (init(&window, &screen) == 1)
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
	
	SDL_Delay(10000);

	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}