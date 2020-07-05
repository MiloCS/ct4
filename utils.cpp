#include <stdlib.h>
#include "game.h"

bool check_rows_cols(int num, int board[ROWS][COLS]) {
	for (int i=0; i<ROWS-3; i++) {
		for (int j=0; j<COLS; j++) {
			if (board[i][j] == num && board[i+1][j] == num && board[i+2][j] == num && board[i+3][j] == num) {
				return true;
			}
		}
	}

	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS-3; j++) {
			if (board[i][j] == num && board[i][j+1] == num && board[i][j+2] == num && board[i][j+3] == num) {
				return true;
			}
		}
	}

	return false;
}

bool diagonals_helper(int i, int j, int row_inc, int col_inc, int num, int board[ROWS][COLS]) {
	for (int h=0; h<4; h++) {
		// cout << (i + row_inc * h) << ", " << (j + col_inc * h) << endl;
		// cout << board[i + row_inc * h][j + col_inc * h] << endl;
		if (board[i + row_inc * h][j + col_inc * h] != num) {
			return false;
		}
	}
	return true;
}

bool check_diagonals(int num, int board[ROWS][COLS]) {
	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS; j++) {
			//subset that can have right-tilted diagonals (+1)
			if (j <= 3) {
				//subset that can have down-tilted diagonals (+1)
				if (i < 3) {
					if (diagonals_helper(i, j, 1, 1, num, board)) {return true;}
				}
				//subset that can have up-tilted diagonals (-1)
				else {
					if (diagonals_helper(i, j, -1, 1, num, board)) {return true;}
				}
			}
			//subset that can have left-tilted diagonals (-1)
			if (j >= 3) {
				//subset that can have down-tilted diagonals (+1)
				if (i < 3) {
					if (diagonals_helper(i, j, 1, -1, num, board)) {return true;}
				}
				//subset that can have up-tilted diagonals (-1)
				else {
					if (diagonals_helper(i, j, -1, -1, num, board)) {return true;}
				}
			}
		}
	}
	return false;
}

bool check_win(int num, int board[ROWS][COLS]) {
	return check_rows_cols(num, board) || check_diagonals(num, board);
}

int put_piece(int col, int num, int board[ROWS][COLS]) {
	for (int i=ROWS-1; i>=0; i--) {
		if (board[i][col] == 0) {
			board[i][col] = num;
			return 0;
		}
	}
	return 1;
}