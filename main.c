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

void init_board(struct field board[8][8])
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j].piece = PAWN;
		}
	}
}

void draw_board(struct field board[8][8], SDL_Surface *screen, SDL_Surface *white_pieces, SDL_Surface *black_pieces, Uint32 dark_color, Uint32 light_color)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			SDL_Rect tile;
			tile.x = BOARDX + j * TILE;
			tile.y = BOARDY + i * TILE;
			tile.w = TILE;
			tile.h = TILE;

			if (i % 2 == 0)
			{
				SDL_FillRect(screen, &tile, dark_color);
				if (j % 2 == 0)
				{
					SDL_FillRect(screen, &tile, light_color);
				}
			}
			else
			{
				SDL_FillRect(screen, &tile, light_color);
				if (j % 2 == 0)
				{
					SDL_FillRect(screen, &tile, dark_color);
				}
			}

			draw_sprite(board[i][j].piece, white_pieces, screen, 10 + j * TILE, 10 + i * TILE, TILE, TILE);
		}
	}
}

int main(int argc, char const *argv[])
{
	struct field board[8][8];

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

	init_board(board);
	
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			printf("%d", board[i][j].piece);
		}
		printf("\n");
	}

	while (quit == 0)
	{
		draw_board(board, screen, white_pieces, black_pieces, DARKBLUE, LIGHTBLUE);
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
						case SDLK_ESCAPE:
							quit = 1;
							break;
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