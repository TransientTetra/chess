#include "headers.h"

//todo:

//draws a sprite on screen, doesn't update window
void draw_sprite(
	int piece,
	SDL_Surface *sprite,
	SDL_Surface *screen,
	int dst_x, int dst_y,
	int width, int height)
{
	int src_x, src_y;
	switch (piece)
	{
		case PAWN:
			src_x = PAWNX;
			src_y = PAWNY;
			break;
		case KNIGHT:
			src_x = KNIGHTX;
			src_y = KNIGHTY;
			break;
		case BISHOP:
			src_x = BISHOPX;
			src_y = BISHOPY;
			break;
		case ROOK:
			src_x = ROOKX;
			src_y = ROOKY;
			break;
		case QUEEN:
			src_x = QUEENX;
			src_y = QUEENY;
			break;
		case KING:
			src_x = KINGX;
			src_y = KINGY;
			break;
	}

	SDL_Rect src_rect;
	src_rect.x = src_x;
	src_rect.y = src_y;
	src_rect.w = width;
	src_rect.h = height;

	SDL_Rect dst_rect;
	dst_rect.x = dst_x;
	dst_rect.y = dst_y;
	dst_rect.w = width;
	dst_rect.h = height;

	SDL_BlitSurface(sprite, &src_rect, screen, &dst_rect);
}

int main(int argc, char const *argv[])
{
	short int quit = 0;
	SDL_Event event;
	SDL_Window *window = NULL;
	SDL_Surface *screen = NULL;
	SDL_Surface *white_pieces = NULL;
	SDL_Surface *black_pieces = NULL;

	if (init(&window, &screen) == 1)
	{
		return 1;
	}

	if (load_graphics(
		&white_pieces, "./art/white.bmp",
		&black_pieces, "./art/black.bmp") == 1)
	{
		SDL_FreeSurface(screen);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	while (quit == 0)
	{
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
						case SDLK_DOWN:
							draw_sprite(KNIGHT, white_pieces, screen, 64, 64, TILE, TILE);
					}
			}
		}
	}

	SDL_FreeSurface(white_pieces);
	SDL_FreeSurface(black_pieces);
	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}