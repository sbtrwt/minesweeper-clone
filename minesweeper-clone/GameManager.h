#pragma once
#define max_mine 99
#define max_side 25
#define max_move 526 


class GameManager
{
private:
	int board[max_side][max_side];
	int side, mines;
public :
	void play();
	void init();
	void clear();
	void printBoard();
	void chooseLevel();
};

