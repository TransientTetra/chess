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
			board[i][j].piece = NONE;
		}
	}

	for (int i = 0; i < 8; ++i)
	{
			board[1][i].piece = PAWN;
			board[1][i].color = WHITE_PIECE;
			board[6][i].piece = PAWN;
			board[6][i].color = BLACK_PIECE;
			if (i == 0 || i == 7)
			{
				board[0][i].piece = ROOK;
				board[0][i].color = WHITE_PIECE;
				board[7][i].piece = ROOK;
				board[7][i].color = BLACK_PIECE;
			}
			if (i == 1 || i == 6)
			{
				board[0][i].piece = KNIGHT;
				board[0][i].color = WHITE_PIECE;
				board[7][i].piece = KNIGHT;
				board[7][i].color = BLACK_PIECE;
			}
			if (i == 2 || i == 5)
			{
				board[0][i].piece = BISHOP;
				board[0][i].color = WHITE_PIECE;
				board[7][i].piece = BISHOP;
				board[7][i].color = BLACK_PIECE;
			}
			if (i == 3)
			{
				board[0][i].piece = KING;
				board[0][i].color = WHITE_PIECE;
				board[7][i].piece = KING;
				board[7][i].color = BLACK_PIECE;
			}
			if (i == 4)
			{
				board[0][i].piece = QUEEN;
				board[0][i].color = WHITE_PIECE;
				board[7][i].piece = QUEEN;
				board[7][i].color = BLACK_PIECE;
			}
	}
}

void draw_board(
	struct field board[8][8],
	struct point pointer,
	SDL_Surface *screen,
	SDL_Surface *white_pieces, SDL_Surface *black_pieces,
	Uint32 dark_color, Uint32 light_color, Uint32 pointer_color)
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
				if (j % 2 == 0)
				{
					SDL_FillRect(screen, &tile, light_color);
				}
				else
				{
					SDL_FillRect(screen, &tile, dark_color);
				}
			}
			else
			{
				if (j % 2 == 0)
				{
					SDL_FillRect(screen, &tile, dark_color);
				}
				else
				{
					SDL_FillRect(screen, &tile, light_color);
				}
			}

			if (j == pointer.x && i == pointer.y)
			{
				SDL_FillRect(screen, &tile, pointer_color);

				SDL_Rect overlay;
				overlay.x = BOARDX + 2 + j * TILE;
				overlay.y = BOARDY + 2 + i * TILE;
				overlay.w = TILE - 4;
				overlay.h = TILE - 4;

				SDL_Rect overlay1;
				overlay1.x = BOARDX + 6 + j * TILE;
				overlay1.y = BOARDY + i * TILE;
				overlay1.w = TILE - 12;
				overlay1.h = TILE;

				SDL_Rect overlay2;
				overlay2.x = BOARDX + j * TILE;
				overlay2.y = BOARDY + 6 + i * TILE;
				overlay2.w = TILE;
				overlay2.h = TILE - 12;

				if (i % 2 == 0)
				{
					if (j % 2 == 0)
					{
						SDL_FillRect(screen, &overlay, light_color);
						SDL_FillRect(screen, &overlay1, light_color);
						SDL_FillRect(screen, &overlay2, light_color);
					}
					else
					{
						SDL_FillRect(screen, &overlay, dark_color);
						SDL_FillRect(screen, &overlay1, dark_color);
						SDL_FillRect(screen, &overlay2, dark_color);
					}
				}
				else
				{
					if (j % 2 == 0)
					{
						SDL_FillRect(screen, &overlay, dark_color);
						SDL_FillRect(screen, &overlay1, dark_color);
						SDL_FillRect(screen, &overlay2, dark_color);
					}
					else
					{
						SDL_FillRect(screen, &overlay, light_color);
						SDL_FillRect(screen, &overlay1, light_color);
						SDL_FillRect(screen, &overlay2, light_color);
					}
				}
			}

			if (board[i][j].color == WHITE_PIECE)
			{
				draw_sprite(board[i][j].piece, white_pieces, screen, 10 + j * TILE, 10 + i * TILE, TILE, TILE);	
			}
			else
			{
				draw_sprite(board[i][j].piece, black_pieces, screen, 10 + j * TILE, 10 + i * TILE, TILE, TILE);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	struct field board[8][8];

	struct point pointer;
	pointer.x = 0;
	pointer.y = 0;
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

	while (quit == 0)
	{
		draw_board(board, pointer, screen, white_pieces, black_pieces, DARKBLUE, LIGHTBLUE, ORANGE);
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
						case SDLK_UP:
							if (pointer.y > 0)
							{
								--pointer.y;
							}
							break;
						case SDLK_DOWN:
							if (pointer.y < 7)
							{
								++pointer.y;
							}
							break;
						case SDLK_LEFT:
							if (pointer.x > 0)
							{
								--pointer.x;
							}
							break;
						case SDLK_RIGHT:
							if (pointer.x < 7)
							{
								++pointer.x;
							}
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