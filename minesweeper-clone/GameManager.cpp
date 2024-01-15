#include <iostream>
#include "GameManager.h"
#include <time.h>
#include <utility>
#include <vector> 
#include <algorithm> 


using namespace std;

void GameManager::play()
{
	//init();
	bool isGameOver = false;
	int moves = 0;
	bool isFirstmove = true;
	do {
		printBoard(false);
		getInput();
		if (isFirstmove) {
			isFirstmove = false;
			init();
		}
		mark_board[row][col] = true;

		moves++;
		if (board[row][col] == '*') {
			isGameOver = true;
			cout << "\n Mine hits ......Game Over try next time....\n";
		}
		if (moves == MAX_MOVE) {
			isGameOver = true;
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
	cout << "\n\t\t\t\t\t\t\t ";
	for (int k = 0; k < side;k++)cout << k << " ";
	cout << "\n";
	for (int i = 0; i < side; i++) {
		cout << "\n\t\t\t\t\t\t\t-";
		
		for (int k = 0; k < side;k++)cout << "--";
		cout << "\n\t\t\t\t\t\t" << i;
		cout << "\t|";
		
		for (int j = 0; j < side; j++) {
			if (board[i][j] == '*')
				cout << (showMines ? board[i][j] : ' ') << "|";
			else if (true  || mark_board[i][j]) {

				int res = getAdjMinesCount(i, j);
				if (res == 0) {
					cout << " |";
				}
				else {
					cout << res<< "|";
				}
				
				
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
	cout << "\t\t\t\t\t\t\tMinesweeper" << endl;
	cout << "\t\t\t\t\t\t\tChoose difficulty level : " << endl;
	cout << "\n\t\t\t\t\t\t\t 1. Beginner \n\t\t\t\t\t\t\t 2. Intermediate \n\t\t\t\t\t\t\t 3. Advanced " << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		side = 9;
		mines = 10;
		break;
	case 2:
		side = 16;
		mines = 40;
		break;
	case 3:
		side = 24;
		mines = 99;
		break;
	default:
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
