#include "Level.h"
#include <time.h>
#include <stdio.h>
#include "Game.h"
#include "UI.h"

int main()
{
	Game game;
	UI UI;
	
	switch (UI.GameMenu())
	{
	case '1':
		game.StartGame();
		break;
	case '2':
		exit;
		break;
	default:
		break;
	}
	

	return 0;
}

