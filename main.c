#include "headers.h"

//todo:
//pieces can move when near the edge 
//pawns can beat pawns or pieces of the same color
//sometimes when attempting to execute program seg fault
//finish rook

int main(int argc, char const *argv[])
{
	struct field board[8][8];

	struct point cursor;
	cursor.x = 0;
	cursor.y = 0;
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

	struct field temp_field;
	struct point temp;
	temp.x = NONE;
	temp.y = NONE;
	temp_field.piece = NONE;
	temp_field.color = NO_COLOR;
	short int picked_up = 0;

	init_board(board);
	set_possible_moves(board);

	while (quit == 0)
	{
		draw_board(board, cursor, screen, white_pieces, black_pieces, DARKBLUE, LIGHTBLUE, ORANGE);
		
		if (picked_up == 1)
		{
			draw_possible_moves(board, screen, temp.x, temp.y, ORANGE);
		}
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
						case SDLK_RETURN:
							if (picked_up == 0)
							{
								set_possible_moves(board);
								if (board[cursor.x][cursor.y].piece != NONE)
								{
									choose_piece(board, cursor, &temp_field, &temp);
									picked_up = 1;
								}
								else
								{
									temp.x = NONE;
									temp.y = NONE;
								}
							}							
							else if (picked_up == 1)
							{
								if (board[temp.x][temp.y].possible[cursor.x][cursor.y] == 1)
								{
									replace_with_chosen(board, cursor, &temp_field, &temp);
								}
								else
								{
									temp.x = NONE;
									temp.y = NONE;
								}
								picked_up = 0;
							}
							break;
						case SDLK_UP:
							if (cursor.x > 0)
							{
								--cursor.x;
							}
							else
							{
								cursor.x = 7;
							}
							break;
						case SDLK_DOWN:
							if (cursor.x < 7)
							{
								++cursor.x;
							}
							else
							{
								cursor.x = 0;
							}
							break;
						case SDLK_LEFT:
							if (cursor.y > 0)
							{
								--cursor.y;
							}
							else
							{
								cursor.y = 7;
							}
							break;
						case SDLK_RIGHT:
							if (cursor.y < 7)
							{
								++cursor.y;
							}
							else
							{
								cursor.y = 0;
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