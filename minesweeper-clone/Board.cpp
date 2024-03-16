#include <iostream>
#include "Board.h"
#include <memory>

using namespace std;
Board::Board()
{
}
Board::Board(int side, int mine)
{
	m_side = side;
	m_mines = mine;
}

Board::~Board()
{
}

void Board::init()
{
	//memset(board, ' ', sizeof(board));
	for (int i = 0; i < m_mines; i++) {
		do {
			int random = rand() % (m_side * m_side);
			int x = random / m_side;
			int y = random % m_side;

			if (m_Tiles[x][y].isBomb()  && x != m_row && y != m_col)
			{
				m_Tiles[x][y].setTileType(TileType::Bomb);
				break;
			}

		} while (true);


	}
}

void Board::clear()
{
	cout << ("\33[2J\33[1;1H");
}

void Board::print()
{
	clear();
	/*if (size_type == 1)
	{
		cout << "\n\t\t\t\t\t\t\t ";
		for (int k = 0; k < m_side;k++)cout << k << " ";
		cout << "\n";
	}*/
	for (int i = 0; i < m_side; i++) {
		cout << "\n\t\t\t\t\t\t\t-";

		for (int k = 0; k < m_side;k++)cout << "--";
		cout << "\n\t\t\t\t\t\t" << i;
		cout << "\t|";

		for (int j = 0; j < m_side; j++) {
			m_Tiles[i][j].print();
		}

	}
	cout << "\n\t\t\t\t\t\t\t-";
	for (int k = 0; k < m_side;k++)cout << "--";

}

void Board::SetBoardSize(BoardSize boardSize)
{
	m_boardSize = boardSize;
}
