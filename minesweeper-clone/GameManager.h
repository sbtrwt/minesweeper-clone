#pragma once
#define MAX_MINE 99
#define MAX_SIDE 25
#define MAX_MOVE 526 


class GameManager
{
private:
	char board[MAX_SIDE][MAX_SIDE];
	bool mark_board[MAX_SIDE][MAX_SIDE];
	int side, mines;
	int row, col;

public :
	GameManager() {
		memset(board, ' ', sizeof(board));
		memset(mark_board, false, sizeof(mark_board));
	}

	void play();
	void init();
	void clear();
	void printBoard(bool showMines = false);
	void chooseLevel();
	void getInput();
	int getAdjMinesCount(int row, int col);
	bool isValidCell(int row, int col);
};

