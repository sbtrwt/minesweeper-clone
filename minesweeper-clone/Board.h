#pragma once
#include "Tile.h"
#include "Position.h"


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
		int m_revealedTileCount;
	public:
		Board();
		Board(int side, int mine);
		
		virtual ~Board();
		void init(Position seedPosition);
		void clear();
		void print();
		void setBoardSize(BoardSize);
		void processInput(Position input);
		void revealTile(Position input);
		bool isValidPosition(Position position) const;
		int getAdjMinesCount(Position input);
		int getHiddenTile();
		bool isMineTile(Position position);
		void setStateAllTiles(TileState);
};

