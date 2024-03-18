#include <iostream>
#include "GameOwner.h"

using namespace std;

GameOwner::GameOwner()
{
	
}

GameOwner::~GameOwner()
{
}

void GameOwner::play()
{
	bool isGameOver = false;

	bool isFirstmove = true;
	
	do {
		m_board.print();
		getInput();
		if (isFirstmove) {
			isFirstmove = false;
			m_board.init(m_input);
		}
		m_board.processInput(m_input);
		

		if (m_board.isMineTile(m_input))
		{ 
			isGameOver = true;
			m_board.setStateAllTiles(TileState::Revealed);
			m_board.print();
			cout << "\n Mine hits ......Game Over try next time....\n";
		}
		if (m_board.getHiddenTile() == 0) {
			isGameOver = true;
			m_board.print();
			cout << "\n You won \n";
		}
	} while (!isGameOver);
}
void GameOwner::clear()
{
	cout << ("\33[2J\33[1;1H");
}
void GameOwner::chooseLevel()
{
	clear();
	cout << "\t\t\t\t\t\t\t-----------------------" << endl;
	cout << "\t\t\t\t\t\t\t|     Minesweeper     |" << endl;
	cout << "\t\t\t\t\t\t\t-----------------------" << endl;
	cout << "\t\t\t\t\t\t\tChoose difficulty level : " << endl;
	cout << "\n\t\t\t\t\t\t\t 1. Beginner \n\t\t\t\t\t\t\t 2. Intermediate \n\t\t\t\t\t\t\t 3. Advanced " << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		m_board = Board(9, 10);
		m_board.setBoardSize(BoardSize::Small);
		
		break;
	case 2:
		m_board = Board(16, 40);
		m_board.setBoardSize(BoardSize::Medium);
		
		break;
	case 3:
		m_board = Board(24, 99);
		m_board.setBoardSize(BoardSize::Large);
		
		break;
	default:
		m_board = Board(9, 10);
		m_board.setBoardSize(BoardSize::Small);
	}
}

void GameOwner::getInput()
{
	cout << "\n\t\t\t\t\t\t\tEnter Position row : ";
	cin >> m_input.x;
	cout << "\n\t\t\t\t\t\t\tEnter Position col : ";
	cin >> m_input.y;
}