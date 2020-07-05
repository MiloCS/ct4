#include <stdlib.h>
#include <iterator>
#include "game.h"
#include "utils.cpp"

void copy_board(int board[ROWS][COLS], int new_board[ROWS][COLS]) {
	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS; j++) {
			new_board[i][j] = board[i][j];
		}
	}
}

int get_ai_play(int board[ROWS][COLS]) {
	return 0;
}

int test_col(int col, int board[ROWS][COLS]) {
	int new_board[ROWS][COLS];
	copy_board(board, new_board);
	put_piece(col, PLAYER_TWO, )
}