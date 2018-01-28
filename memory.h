#include "lib.h"

//initializes sdl, creates window and screen
int init(SDL_Window **window, SDL_Surface **screen);

//loads graphics
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
	SDL_Surface **bishop_black, const char *bishop_black_location);