#pragma once
#include "Tile.h"


#define MAX_MINE 99
#define MAX_SIDE 25


enum class BoardSize
{
	Small,
	Medium,
	Large
};

class Board
{
	private:
		BoardSize m_boardSize;
		Tile m_Tiles[MAX_SIDE][MAX_SIDE];
		int m_row, m_col;
		int m_side, m_mines;
	public:
		Board();
		Board(int side, int mine);
		
		virtual ~Board();
		void init();
		void clear();
		void print();
		void SetBoardSize(BoardSize);

};

