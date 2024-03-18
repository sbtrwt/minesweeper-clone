
#include <iostream>
#include "GameManager.h"
#include "GameOwner.h"


int main()
{
	GameOwner game;
	game.chooseLevel();
	game.play();
	
	system("pause");
	return 0;
}
