#include <iostream>
#include <string>
#include <stdlib.h>
#include "game.h"
#include "ai.cpp"

using namespace std;

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

bool validate_input (string str_input) {
	int input;
	try {
		input = stoi(str_input);
	}
	catch (...) {
		return false;
	}
	if (input != -1 && input != 0 && input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6) {
		return false;
	}
	return true;
}

int get_input() {
	string input;
	cout << "Enter a column to play in (-1 to exit)> ";
	cin >> input;

	while(!validate_input(input)) {
		cout << "Invalid. Enter a column to play in (-1 to exit)> ";
		cin >> input;
   }
   return stoi(input);
}

void main_game_loop() {
	cout << "Do you have another person to play with (y/n)> ";
	string two_players;
	cin >> two_players;
	if (two_players == "y" || two_players == "Y") {
		print_board();
    	int input;
    	while(input != -1) {
	    	cout << "Player 1: ";
	    	input = get_input();
	    	if (input == -1) {break;}
	    	put_piece(input, PLAYER_ONE, board);
	    	if (check_win(PLAYER_ONE, board)) {
	    		print_board();
	    		cout << "player 1 wins" << endl;
	    		break;
	    	}
	    	cout << endl;
	    	print_board();
	    	cout << "Player 2: ";
	    	input = get_input();
	    	if (input == -1) {break;}
	    	put_piece(input, PLAYER_TWO, board);
	    	if (check_win(PLAYER_TWO, board)) {
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
	    	input = get_input();
	    	if (input == -1) {break;}
	    	put_piece(input, PLAYER_ONE, board);
	    	if (check_win(PLAYER_ONE, board)) {
	    		print_board();
	    		cout << "you win" << endl;
	    		break;
	    	}
	    	put_piece(get_ai_play(board), PLAYER_TWO, board);
	    	if (check_win(PLAYER_TWO, board)) {
	    		print_board();
	    		cout << "ai wins" << endl;
	    		break;
	    	}
    		print_board();
    	}
	}
}

int main()
{
	//initializing the board with 0s, which represent blank spots
	for (int i=0; i<ROWS; i++) {
		for (int j=0; j<COLS; j++) {
			board[i][j] = 0;
		}
	}
	main_game_loop();
    //cout << test_method() << endl;

    return 0;
}