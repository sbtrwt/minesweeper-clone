#include <iostream>
#include "Board.h"
#include <memory>
#include "Position.h"

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

			if (!m_Tiles[x][y].isBomb()  && x != m_row && y != m_col)
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

void Board::setBoardSize(BoardSize boardSize)
{
	m_boardSize = boardSize;
}

void Board::processInput(Position input)
{
	revealTile(input);
}

bool Board::isValidPosition(Position position) const
{
	return (0 <= position.x && position.x < m_side) && (0 <= position.y && position.y < m_side);
}

void Board::revealTile(Position input)
{
	if (this->m_Tiles[input.x][input.y].isRevealed() || !this->isValidPosition(input))
		return;

	if (this->isValidPosition(input)) {
		this->m_Tiles[input.x][input.y].setTileState(TileState::Revealed);
		int count = getAdjMinesCount(input);
		this->m_Tiles[input.x][input.y].setadjBombCount(count);
		if (count == 0)
		{
			revealTile(Position(input.x, input.y-1));
			revealTile(Position(input.x, input.y + 1));
			revealTile(Position(input.x-1, input.y ));
			revealTile(Position(input.x+1, input.y ));

		}
	}
}
int Board::getAdjMinesCount(Position input)
{
	int result = 0;
	if (isValidPosition(Position(input.x-1, input.y - 1)) && m_Tiles[input.x-1][input.y-1].isBomb()) result++;
	if (isValidPosition(Position(input.x+1, input.y + 1)) && m_Tiles[input.x+1][input.y+1].isBomb()) result++;
	if (isValidPosition(Position(input.x-1, input.y + 1)) && m_Tiles[input.x-1][input.y+1].isBomb()) result++;
	if (isValidPosition(Position(input.x+1, input.y - 1)) && m_Tiles[input.x+1][input.y-1].isBomb()) result++;


	if (isValidPosition(Position(input.x, input.y - 1)) && m_Tiles[input.x][input.y-1].isBomb()) result++;
	if (isValidPosition(Position(input.x, input.y + 1)) && m_Tiles[input.x][input.y+1].isBomb()) result++;
	if (isValidPosition(Position(input.x-1, input.y)) && m_Tiles[input.x-1][input.y].isBomb()) result++;
	if (isValidPosition(Position(input.x+1, input.y)) && m_Tiles[input.x+1][input.y].isBomb()) result++;

	return result;
}
