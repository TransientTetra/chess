#include "headers.h"

//draws a sprite on screen, doesn't update window
void draw_sprite(
	int piece,
	SDL_Surface *sprite,
	SDL_Surface *screen,
	int dst_x, int dst_y,
	int width, int height)
{
	SDL_Rect src_rect;

	switch (piece)
	{
		case PAWN:
			src_rect.x = PAWNX;
			src_rect.y = PAWNY;
			break;
		case KNIGHT:
			src_rect.x = KNIGHTX;
			src_rect.y = KNIGHTY;
			break;
		case BISHOP:
			src_rect.x = BISHOPX;
			src_rect.y = BISHOPY;
			break;
		case ROOK:
			src_rect.x = ROOKX;
			src_rect.y = ROOKY;
			break;
		case QUEEN:
			src_rect.x = QUEENX;
			src_rect.y = QUEENY;
			break;
		case KING:
			src_rect.x = KINGX;
			src_rect.y = KINGY;
			break;
	}

	src_rect.w = width;
	src_rect.h = height;

	SDL_Rect dst_rect;
	dst_rect.x = dst_x;
	dst_rect.y = dst_y;
	dst_rect.w = width;
	dst_rect.h = height;

	SDL_BlitSurface(sprite, &src_rect, screen, &dst_rect);
}

//depending on x it either draws a rect with one color or another
void modulo2_draw_rect(int x, SDL_Rect *rect, SDL_Surface *screen, Uint32 color1, Uint32 color2)
{
	if (x % 2 == 0)
	{
		SDL_FillRect(screen, rect, color1);
	}
	else
	{
		SDL_FillRect(screen, rect, color2);
	}

}

//draws board, chess pieces and pointer
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
				modulo2_draw_rect(j, &tile, screen, light_color, dark_color);
			}
			else
			{
				modulo2_draw_rect(j, &tile, screen, dark_color, light_color);
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
					modulo2_draw_rect(j, &overlay, screen, light_color, dark_color);
					modulo2_draw_rect(j, &overlay1, screen, light_color, dark_color);
					modulo2_draw_rect(j, &overlay2, screen, light_color, dark_color);
				}
				else
				{
					modulo2_draw_rect(j, &overlay, screen, dark_color, light_color);
					modulo2_draw_rect(j, &overlay1, screen, dark_color, light_color);
					modulo2_draw_rect(j, &overlay2, screen, dark_color, light_color);
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