
#include <iostream>
#include "GameManager.h"
#include "GameOwner.h"


int main()
{
	//GameManager gm;
	//gm.chooseLevel();
	//gm.play();

	GameOwner game;
	game.chooseLevel();
	game.play();
	
	system("pause");
	return 0;
}
