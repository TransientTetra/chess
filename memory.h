#include "lib.h"

//initializes sdl, creates window and screen
int init(SDL_Window **window, SDL_Surface **screen);

//loads bitmaps for white and black pieces
int load_graphics(
	SDL_Surface **white_pieces, const char *white_location,
	SDL_Surface **black_pieces, const char *black_location);

//initializes board array with initial chess layout
void init_board(struct field board[8][8]);