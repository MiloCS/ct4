#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define COLS 7
#define ROWS 6

int board[ROWS][COLS];


string translate_piece(int num) {
	if (num == 1) {
		return "O";
	}
	else if (num == -1) {
		return "X";
	}
	else {
		return "_";
	}
}

//function that prints out the board to the console
void print_board() {
	cout << "  _____________________________" << endl;
	for (int i=0; i<ROWS; i++) {
		cout << "  |";
		for (int j=0; j<COLS; j++) {
			cout << "_" + translate_piece(board[i][j]) + "_|";
		}
		cout << endl;
	}
	cout << endl;
}

bool check_rows_cols(int num) {
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

bool diagonals_helper(int i, int j, int row_inc, int col_inc, int num) {
	for (int h=0; h<4; h++) {
		// cout << (i + row_inc * h) << ", " << (j + col_inc * h) << endl;
		// cout << board[i + row_inc * h][j + col_inc * h] << endl;
		if (board[i + row_inc * h][j + col_inc * h] != num) {
			return false;
		}
	}
	return true;
}

bool check_diagonals(int num) {
	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS; j++) {
			//subset that can have right-tilted diagonals (+1)
			if (j <= 3) {
				//subset that can have down-tilted diagonals (+1)
				if (i < 3) {
					if (diagonals_helper(i, j, 1, 1, num)) {return true;}
				}
				//subset that can have up-tilted diagonals (-1)
				else {
					if (diagonals_helper(i, j, -1, 1, num)) {return true;}
				}
			}
			//subset that can have left-tilted diagonals (-1)
			if (j >= 3) {
				//subset that can have down-tilted diagonals (+1)
				if (i < 3) {
					if (diagonals_helper(i, j, 1, -1, num)) {return true;}
				}
				//subset that can have up-tilted diagonals (-1)
				else {
					if (diagonals_helper(i, j, -1, -1, num)) {return true;}
				}
			}
		}
	}
	return false;
}

bool check_win(int num) {
	return check_rows_cols(num) || check_diagonals(num);
}

int put_piece(int col, int num) {
	for (int i=ROWS-1; i>=0; i--) {
		if (board[i][col] == 0) {
			board[i][col] = num;
			return 0;
		}
	}
	return 1;
}

int get_ai_play() {
	return rand() % 7;
}

int main()
{
	//initializing the board with 0s, which represent blank spots
	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS; j++) {
			board[i][j] = 0;
		}
	}
	cout << "Do you have another person to play with (y/n)> ";
	string two_players;
	cin >> two_players;
	if (two_players == "y" || two_players == "Y") {
		print_board();
    	int input;
    	while(input != -1) {
	    	cout << "Player 1: Enter a column to play in (-1 to exit)> ";
	    	cin >> input;
	    	put_piece(input, 1);
	    	if (check_win(1)) {
	    		print_board();
	    		cout << "player 1 wins" << endl;
	    		break;
	    	}
	    	cout << "Player 2: Enter a column to play in (-1 to exit)> ";
	    	cin >> input;
	    	put_piece(input, -1);
	    	if (check_win(-1)) {
	    		print_board();
	    		cout << "player 2 wins" << endl;
	    		break;
	    	}
    		print_board();
    	}
	}
	else {
		print_board();
    	int input;
    	while(input != -1) {
	    	cout << "Enter a column to play in (-1 to exit)> ";
	    	cin >> input;
	    	put_piece(input, 1);
	    	if (check_win(1)) {
	    		print_board();
	    		cout << "you win" << endl;
	    		break;
	    	}
	    	put_piece(get_ai_play(), -1);
	    	if (check_win(-1)) {
	    		print_board();
	    		cout << "ai wins" << endl;
	    		break;
	    	}
    		print_board();
    	}
	}
	
    

    return 0;
}