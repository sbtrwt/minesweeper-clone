#include <iostream>
#include "GameManager.h"
#include <time.h>
using namespace std;

void GameManager::play()
{
}

void GameManager::init()
{
}
void GameManager::clear()
{
	cout << ("\33[2J\33[1;1H");
}

void GameManager::printBoard()
{
}

void GameManager::chooseLevel()
{
	clear();
	cout << "Minesweeper"<<endl;
	cout << "Choose difficulty level : " << endl;
	cout << "\n 1. Beginner \n 2. Intermediate \n 3. Advanced " << endl;
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