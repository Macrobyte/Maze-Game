#pragma once
#include "Game.h"
#include "Level.h"
#include "UI.h"
#include <iostream>


class Game
{	
	UI UI;
	Level level;


public:
	Game();

	void StartGame();
	void EndGame();
	void ShowUI();



	

};


