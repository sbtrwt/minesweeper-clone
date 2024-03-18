#pragma once
#include "Board.h"
#include "Position.h"
class GameOwner
{
private:
	Board m_board;
	Position m_input;
public:
	GameOwner();
	virtual ~GameOwner();

	void play();
	void clear();
	void chooseLevel();
	void getInput();
};

