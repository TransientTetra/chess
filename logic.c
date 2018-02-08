#include "headers.h"

void replace_with_chosen(
	struct field board[8][8],
	struct point cursor,
	struct field *temp_field,
	struct point *temp)
{	
	if (board[cursor.x][cursor.y].piece != temp_field->piece || board[cursor.x][cursor.y].color != temp_field->color)
	{
		board[cursor.x][cursor.y].piece = temp_field->piece;
		board[cursor.x][cursor.y].color = temp_field->color;
		board[temp->x][temp->y].piece = NONE;
		board[temp->x][temp->y].color = NO_COLOR;
	}
	temp_field->piece = NONE;
	temp_field->color = NO_COLOR;
	temp->x = NONE;
	temp->y = NONE;
}

void choose_piece(
	struct field board[8][8],
	struct point cursor,
	struct field *temp_field,
	struct point *temp)
{
	temp_field->piece = board[cursor.x][cursor.y].piece;
	temp_field->color = board[cursor.x][cursor.y].color;
	temp->x = cursor.x;
	temp->y = cursor.y;
}

void set_possible_moves(struct field board[8][8])
{
	zero_possible_moves(board);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			switch(board[i][j].piece)
			{
				case PAWN:
					if (board[i][j].color == WHITE_PIECE)
					{
						pawn_filter(board, i, j, 1, 1);
					}
					else
					{
						pawn_filter(board, i, j, -1, 6);
					}
					break;
				case KNIGHT:
					ez_filter(board, i, j, 2, 1);
					ez_filter(board, i, j, 2, -1);
					ez_filter(board, i, j, -2, 1);
					ez_filter(board, i, j, -2, -1);
					ez_filter(board, i, j, 1, 2);
					ez_filter(board, i, j, -1, 2);
					ez_filter(board, i, j, 1, -2);
					ez_filter(board, i, j, -1, -2);
					break;
				case KING:
					ez_filter(board, i, j, 1, 0);
					ez_filter(board, i, j, 1, 1);
					ez_filter(board, i, j, 1, -1);
					ez_filter(board, i, j, 0, 1);
					ez_filter(board, i, j, 0, -1);
					ez_filter(board, i, j, -1, 0);
					ez_filter(board, i, j, -1, -1);
					ez_filter(board, i, j, -1, 1);
					break;
				case ROOK:
					for (int k = i + 1; k < 8; ++k)
					{
						if (rook_filter(board, i, j, k, j) != 0)
						{
							break;
						}
					}
					for (int k = i - 1; k >= 0; --k)
					{
						if (rook_filter(board, i, j, k, j) != 0)
						{
							break;
						}
					}
					for (int k = j + 1; k < 8; ++k)
					{
						if (rook_filter(board, i, j, i, k) != 0)
						{
							break;
						}
					}
					for (int k = j - 1; k >= 0; --k)
					{
						if (rook_filter(board, i, j, i, k) != 0)
						{
							break;
						}
					}
					break;
			}
		}
	}
}

int rook_filter(struct field board[8][8], int a, int b, int c, int d)
{
	if (board[c][d].piece == NONE)
	{
		board[a][b].possible[c][d] = 1;
	}
	else if (board[c][d].color != board[a][b].color)
	{
		board[a][b].possible[c][d] = 1;
		return 1;
	}
	else
	{
		return 1;
	}
	return 0;
}

void ez_filter(struct field board[8][8], int i, int j, int vertical, int horizontal)
{
	if (board[i + vertical][j + horizontal].color != board[i][j].color)
	{
		board[i][j].possible[i + vertical][j + horizontal] = 1;
	}
}

void pawn_filter(struct field board[8][8], int i, int j, int color, int row)
{	
	if (board[i + color][j].piece == NONE)
	{
		board[i][j].possible[i + color][j] = 1;
		if (i == row)
		{
			if (board[i + 2 * color][j].piece == NONE)
			{
				board[i][j].possible[i + 2 * color][j] = 1;
			}
		}
	}
	if (board[i + color][j + 1].piece != NONE)
	{
		board[i][j].possible[i + color][j + 1] = 1;
	}
	if (board[i + color][j - 1].piece != NONE)
	{
		board[i][j].possible[i + color][j - 1] = 1;
	}
}

void zero_possible_moves(struct field board[8][8])
{
	//4096 iterations of the loop below
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				for (int l = 0; l < 8; ++l)
				{
					board[i][j].possible[k][l] = 0;
				}
			}			
		}
	}
}