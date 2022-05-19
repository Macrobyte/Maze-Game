#include "Game.h"

Game::Game()
{

}

void Game::StartGame()
{
	level.CreateLevel();

	
	char input = ' ';
	while (input != UI.Esc)
	{
		if (_kbhit())
		{
			input = _getch();
			level.HandlePlayerMovement(input);
		}

		level.HandleEnemyMovement();

		level.GetPlayer()->KillTimer();


		if (level.GetPlayer()->GetLives() <= 0)
		{
			
			break;
		}

		//UI
		ShowUI();

		if (level.GetPlayer()->GetCanKill())
		{
			UI.SetCursor(44, 11);
			UI.SetTextColor(UI.Red);
			std::cout << level.GetPlayer()->GetKillTimer() << "s ";
		}
		else
		{
			UI.Print(44, 11, "Off ",UI.Red);
		}

		UI.Print(40, 15, level.GetPlayer()->GetScore(),UI.Bright_Yellow);

		UI.Print(40, 13, level.GetPlayer()->GetLives(),UI.Green);
	}

	EndGame();
	
}

void Game::EndGame()
{
	level.GameOver();

	UI.ClearScreen();

	UI.SetCursor(0, 0);

	switch (UI.GameOverMenu())
	{
	case '1':
		StartGame();
		break;
	case '2':
		exit;
		break;
	default:
		break;
	}
}

void Game::ShowUI()
{
	UI.Print(25, 1, "Welcome to my maze game!");

	UI.Print(25, 3, "Player : ");
	UI.Print(35, 3, char(2), UI.Green);

	UI.Print(25, 5, "Enemies : ");
	UI.Print(36, 5, char(1), UI.Red);

	UI.Print(25, 7, "Kill Fruits : ");
	UI.Print(39, 7, char(254), UI.Magenta);

	UI.Print(25, 9, "Coins : ");
	UI.Print(34, 9, char(254), UI.Bright_Yellow);

	UI.Print(25, 11, "Kill Fruit Effect: ");

	UI.Print(25, 13, "Player Lives: ");

	UI.Print(25, 15, "Player Score: ");

	UI.Print(25, 17, "Objective: Complete the most levels without dying!");

	UI.Print(25, 21, "Press", UI.White);
	UI.Print(30, 21, "'Escape'", UI.Red);
	UI.Print(38, 21, "to end game! ", UI.White);

}


