#include "lib.h"

//draws a sprite on screen, doesn't update window
void draw_sprite(
	int piece,
	SDL_Surface *sprite,
	SDL_Surface *screen,
	int dst_x, int dst_y,
	int width, int height);

//depending on x it either draws a rect with one color or another
void modulo2_draw_rect(int x, SDL_Rect *rect, SDL_Surface *screen, Uint32 color1, Uint32 color2);

//draws board, chess pieces and pointer
void draw_board(
	struct field board[8][8],
	struct point pointer,
	SDL_Surface *screen,
	SDL_Surface *white_pieces, SDL_Surface *black_pieces,
	Uint32 dark_color, Uint32 light_color, Uint32 pointer_color);

void draw_possible_moves(struct field board[8][8], SDL_Surface *screen, int x, int y, Uint32 color);