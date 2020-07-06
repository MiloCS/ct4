void copy_board(int board[ROWS][COLS], int new_board[ROWS][COLS]);
int test_col(int col, int num, int board[ROWS][COLS]);
int get_ai_play(int board[ROWS][COLS]);
int minimax(int depth, int turn, int board[ROWS][COLS]);