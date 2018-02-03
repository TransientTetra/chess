#include "headers.h"

//initializes sdl, creates window and screen
int init(SDL_Window **window, SDL_Surface **screen)
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

	*screen = SDL_GetWindowSurface(*window);
	if (*screen == NULL)
	{
		fprintf(stderr, "Screen could not be created! SDL Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(*window);
		return 1;
	}

	SDL_ShowCursor(SDL_DISABLE);
	return 0;
}

//loads bitmaps for white and black pieces
int load_graphics(
	SDL_Surface **white_pieces, const char *white_location,
	SDL_Surface **black_pieces, const char *black_location)
{
	*white_pieces = SDL_LoadBMP(white_location);
	if (*white_pieces == NULL)
	{
		fprintf(stderr, "couldn't load white_pieces\n");
		return 1;
	}
	*black_pieces = SDL_LoadBMP(black_location);
	if (*black_pieces == NULL)
	{
		fprintf(stderr, "couldn't load black_pieces\n");
		SDL_FreeSurface(*white_pieces);
		return 1;
	}
	return 0;
}

//initializes board array with initial chess layout
void init_board(struct field board[8][8])
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j].piece = NONE;
			board[i][j].color = NONE;
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