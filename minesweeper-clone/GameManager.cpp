#include <iostream>
#include "GameManager.h"
#include <time.h>
#include <utility>
#include <vector> 
#include <algorithm> 


using namespace std;

void GameManager::play()
{

	bool isGameOver = false;

	bool isFirstmove = true;
	do {
		printBoard(false);
		getInput();
		if (isFirstmove) {
			isFirstmove = false;
			init();
		}

		setVisible(row, col);

		if (board[row][col] == '*') {
			isGameOver = true;
			printBoard(true);
			cout << "\n Mine hits ......Game Over try next time....\n";
		}
		if (getMarkCount() == 0) {
			isGameOver = true;
			printBoard(true);
			cout << "\n You won \n";
		}
	} while (!isGameOver);



}

void GameManager::init()
{
	memset(board, ' ', sizeof(board));
	for (int i = 0; i < mines; i++) {
		do {
			int random = rand() % (side * side);
			int x = random / side;
			int y = random % side;

			if (board[x][y] != '*' && x != row && y != col)
			{
				board[x][y] = '*';
				break;
			}

		} while (true);


	}
}
void GameManager::clear()
{
	cout << ("\33[2J\33[1;1H");
}

void GameManager::printBoard(bool showMines)
{
	clear();
	if (size_type == 1)
	{
		cout << "\n\t\t\t\t\t\t\t ";
		for (int k = 0; k < side;k++)cout << k << " ";
		cout << "\n";
	}
	for (int i = 0; i < side; i++) {
		cout << "\n\t\t\t\t\t\t\t-";

		for (int k = 0; k < side;k++)cout << "--";
		cout << "\n\t\t\t\t\t\t" << i;
		cout << "\t|";

		for (int j = 0; j < side; j++) {
			if (board[i][j] == '*')
				cout << (showMines ? board[i][j] : ' ') << "|";
			else if (mark_board[i][j]) {
				int res = getAdjMinesCount(i, j);
				cout << res << "|";
			}
			else {
				cout << " |";
			}
		}

	}
	cout << "\n\t\t\t\t\t\t\t-";
	for (int k = 0; k < side;k++)cout << "--";


}

void GameManager::chooseLevel()
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
		size_type = 1;
		side = 9;
		mines = 10;
		break;
	case 2:
		size_type = 2;
		side = 16;
		mines = 40;
		break;
	case 3:
		size_type = 3;
		side = 24;
		mines = 99;
		break;
	default:
		size_type = 1;
		side = 9;
		mines = 10;
	}
}

void GameManager::getInput()
{
	cout << "\n\t\t\t\t\t\t\tEnter Position row : ";
	cin >> row;
	cout << "\n\t\t\t\t\t\t\tEnter Position col : ";
	cin >> col;
}

int GameManager::getAdjMinesCount(int row, int col)
{
	int result = 0;
	if (isValidCell(row - 1, col - 1) && board[row - 1][col - 1] == '*') result++;
	if (isValidCell(row + 1, col + 1) && board[row + 1][col + 1] == '*') result++;
	if (isValidCell(row + 1, col - 1) && board[row + 1][col - 1] == '*') result++;
	if (isValidCell(row - 1, col + 1) && board[row - 1][col + 1] == '*') result++;

	if (isValidCell(row - 1, col) && board[row - 1][col] == '*') result++;
	if (isValidCell(row + 1, col) && board[row + 1][col] == '*') result++;
	if (isValidCell(row, col - 1) && board[row][col - 1] == '*') result++;
	if (isValidCell(row, col + 1) && board[row][col + 1] == '*') result++;
	return result;
}

bool GameManager::isValidCell(int row, int col)
{
	return (0 <= row && row < side) && (0 <= col && col < side);
}

void GameManager::setVisible(int row, int col)
{
	if (this->mark_board[row][col] || !this->isValidCell(row, col))
		return;

	if (this->isValidCell(row, col)) {
		this->mark_board[row][col] = true;

		if (getAdjMinesCount(row, col) == 0)
		{
			setVisible(row, col - 1);
			setVisible(row, col + 1);
			setVisible(row - 1, col);
			setVisible(row + 1, col);

		}
	}
}

int GameManager::getMarkCount()
{
	int count = 0;
	for (int i = 0; i < side;i++) {
		for (int j = 0; j < side;j++) {
			if (mark_board[i][j])count++;
		}
	}
	return (side * side - count - mines);
}