#include "Tile.h"
#include <iostream>
using namespace std;

Tile::Tile()
{
}

Tile::~Tile()
{
}

TileType Tile::getTileType()
{
	return m_type;
}

void Tile::setTileType(TileType type)
{
	m_type = type;
}

TileState Tile::getTileState()
{
	return m_state;
}

void Tile::setTileState(TileState tileState)
{
	m_state = tileState;
}

bool Tile::checkTileType(TileType type)
{
	return m_type == type;
}

bool Tile::isBomb()
{
	return  m_type == TileType::Bomb;
}

bool Tile::isEmpty()
{
	return  m_type == TileType::Empty;
}

void Tile::print()
{
	if (isBomb())
		cout << (m_state == TileState::Revealed ? '*' : ' ') << "|";
	else if (m_state == TileState::Revealed) {
		
		cout << m_adjacentBombCount << "|";
	}
	else {
		cout << " |";
	}
}
