#include <stdlib.h>
#include <iterator>
#include "game.h"
#include "utils.cpp"
#include "ai.h"

void copy_board(int board[ROWS][COLS], int new_board[ROWS][COLS]) {
	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS; j++) {
			new_board[i][j] = board[i][j];
		}
	}
}

int test_col(int col, int num, int board[ROWS][COLS]) {
	int new_board[ROWS][COLS];
	copy_board(board, new_board);
	put_piece(col, num, new_board);
	int score = 0;
	if (check_win(num, new_board)) {
		score = 1;
	}
	return score;
}

int get_ai_play(int board[ROWS][COLS]) {
	int min = 1;
	int min_col = 0;
	for (int i=0; i<COLS; i++) {
		int new_board[ROWS][COLS];
		copy_board(board, new_board);
		put_piece(i, PLAYER_TWO, new_board);
		int result = minimax(3, PLAYER_ONE, new_board);
		if (result < min) {
			min = result;
			min_col = i;
		}
	}
	return min_col;
}


int minimax(int depth, int turn, int board[ROWS][COLS]) {
	if (check_win(PLAYER_ONE, board)) {
		return 1;
	}
	if (check_win(PLAYER_TWO, board)) {
		return -1;
	}
	if (depth == 0) {
		return 0;
	}
	int min = 1;
	int max = -1;
	// int min_col = 0;
	// int max_col = 0;
	for (int i=0; i<COLS; i++) {
		int new_board[ROWS][COLS];
		copy_board(board, new_board);
		put_piece(i, turn, new_board);
		int result = minimax(depth - 1, turn * -1, new_board);
		cout << result;
		if (result > max) {
			max = result;
		}
		if (result < min) {
			min = result;
		}
	}
	cout << endl;
	if (turn == PLAYER_ONE) {
		return max;
	}
	else {
		return min;
	}
}