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
				case ROOK:
					parallel_filter(board, i, j);
					break;
				case BISHOP:
					diagonal_filter(board, i, j);
					break;
				case QUEEN:
					diagonal_filter(board, i, j);
					parallel_filter(board, i, j);
					break;
				case KING:
					for (int i = 0; i < 8; ++i)
					{
						/* code */
					}
			}
		}
	}
}

void diagonal_filter(struct field board[8][8], int i, int j)
{
	for (int k = i + 1; k < 8; ++k)
	{
		short int brk = 0;
		for (int l = j + 1; l < 8; ++l)
		{
			if (k - i == l - j)
			{
				if (general_filter(board, i, j, k, l) == 1)
				{
					brk = 1;
					break;
				}
			}
		}
		if (brk != 0)
		{
			break;
		}
	}
	for (int k = i - 1; k >= 0; --k)
	{
		short int brk = 0;
		for (int l = j - 1; l >= 0; --l)
		{
			if (k - i == l - j)
			{
				if (general_filter(board, i, j, k, l) == 1)
				{
					brk = 1;
					break;
				}
			}
		}
		if (brk != 0)
		{
			break;
		}
	}
	for (int k = i + 1; k < 8; ++k)
	{
		short int brk = 0;
		for (int l = j - 1; l >= 0; --l)
		{
			if (k - i == j - l)
			{
				if (general_filter(board, i, j, k, l) == 1)
				{
					brk = 1;
					break;
				}
			}
		}
		if (brk != 0)
		{
			break;
		}
	}
	for (int k = i - 1; k >= 0; --k)
	{
		short int brk = 0;
		for (int l = j + 1; l < 8; ++l)
		{
			if (i - k == l - j)
			{
				if (general_filter(board, i, j, k, l) == 1)
				{
					brk = 1;
					break;
				}
			}
		}
		if (brk != 0)
		{
			break;
		}
	}
}

void parallel_filter(struct field board[8][8], int i, int j)
{
	for (int k = i + 1; k < 8; ++k)
	{
		if (general_filter(board, i, j, k, j) != 0)
		{
			break;
		}
	}
	for (int k = i - 1; k >= 0; --k)
	{
		if (general_filter(board, i, j, k, j) != 0)
		{
			break;
		}
	}
	for (int k = j + 1; k < 8; ++k)
	{
		if (general_filter(board, i, j, i, k) != 0)
		{
			break;
		}
	}
	for (int k = j - 1; k >= 0; --k)
	{
		if (general_filter(board, i, j, i, k) != 0)
		{
			break;
		}
	}

}

int general_filter(struct field board[8][8], int a, int b, int c, int d)
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

void pawn_filter(struct field board[8][8], int i, int j, int vertical, int row)
{	
	if (board[i + vertical][j].piece == NONE)
	{
		board[i][j].possible[i + vertical][j] = 1;
		if (i == row)
		{
			if (board[i + 2 * vertical][j].piece == NONE)
			{
				board[i][j].possible[i + 2 * vertical][j] = 1;
			}
		}
	}
	if (j < 7)
	{
		if (board[i + vertical][j + 1].piece != NONE && board[i + vertical][j + 1].color != board[i][j].color)
		{
			board[i][j].possible[i + vertical][j + 1] = 1;
		}		
	}
	if (j > 0)
	{
		if (board[i + vertical][j - 1].piece != NONE && board[i + vertical][j - 1].color != board[i][j].color)
		{
			board[i][j].possible[i + vertical][j - 1] = 1;
		}
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