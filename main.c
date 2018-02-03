#include "headers.h"

//todo:


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
						case SDLK_RETURN:
							printf("%d %d\n", board[pointer.y][pointer.x].piece, board[pointer.y][pointer.x].color);
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