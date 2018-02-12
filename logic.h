#include "lib.h"

void replace_with_chosen(
	struct field board[8][8],
	struct point cursor,
	struct field *temp_field,
	struct point *temp);

void choose_piece(
	struct field board[8][8],
	struct point cursor,
	struct field *temp_field,
	struct point *temp);

void zero_possible_moves(struct field board[8][8]);

void set_possible_moves(struct field board[8][8]);

void pawn_filter(struct field board[8][8], int i, int j, int vertical, int row);

int general_filter(struct field board[8][8], int a, int b, int c, int d);

void parallel_filter(struct field board[8][8], int i, int j);

void diagonal_filter(struct field board[8][8], int i, int j);