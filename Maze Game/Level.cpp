#include "Level.h"

#include<iostream>
#include<conio.h>
#include<random>
#include <time.h>



Level::Level()
{
	srand(time(NULL));

	if (player == nullptr)
	{
		player = new Player();
	}
	
}

Level::~Level()
{
	delete player;

	DeleteObjects();;
}

void Level::CreateLevel()
{
	//Build and print maze
	maze.create();
	maze.print();

	//Spawn Player
	player->SetPosition(maze.GetStartPos());
	player->SetLives(3);
	maze.PlaceObject(player);

	//Creating Exit Door
	exitDoor.SetPosition(maze.GetExitPos());
	exitDoor.SetSymbol(char(175));
	maze.PlaceObject(&exitDoor);
	maze.GetCell(exitDoor.GetPosition()).obj = &exitDoor;


	//Spawn enemies in maze
	for (int i = 0; i < enemyQty; i++)
	{
		enemies.push_back(new Enemy(maze.GetRandomExitPos()));
		maze.PlaceObject(enemies[i]);
	}

	//Spawn coins in maze
	for (int i = 0; i < coinQty; i++)
	{
		coins.push_back(new Coin(maze.GetRandomPos()));
		maze.PlaceObject(coins[i]);
	}

	//Spawn killfruit in maze
	for (int i = 0; i < killFruitQty; i++)
	{
		killFruits.push_back(new KillFruit(maze.GetRandomPos()));
		maze.PlaceObject(killFruits[i]);	
	}
}

void Level::NextLevel()
{
	DeleteObjects();
	CreateLevel();
}

void Level::GameOver()
{
	DeleteObjects();
}

void Level::HandlePlayerMovement(char input)
{

	switch (input)
	{
	case ArrowUp:

		if (maze.CheckUp(player->GetPosition()).display == maze.getWallChar()) break;

		if (HandleCollision(*player, maze.CheckUp(player->GetPosition()).obj))
		{
			maze.RemoveObject(player->GetPosition());
			player->MoveUp();
			maze.PlaceObject(player);
		}

		break;
	case ArrowDown:

		if (maze.CheckDown(player->GetPosition()).display == maze.getWallChar()) break;

		if (HandleCollision(*player, maze.CheckDown(player->GetPosition()).obj))
		{
			maze.RemoveObject(player->GetPosition());
			player->MoveDown();
			maze.PlaceObject(player);
		}

		break;
	case ArrowLeft:

		if (maze.CheckLeft(player->GetPosition()).display == maze.getWallChar()) break;

		if (HandleCollision(*player, maze.CheckLeft(player->GetPosition()).obj))
		{
			maze.RemoveObject(player->GetPosition());
			player->MoveLeft();
			maze.PlaceObject(player);
		}

		break;
	case ArrowRight:

		if (maze.CheckRight(player->GetPosition()).display == maze.getWallChar()) break;

		if (HandleCollision(*player, maze.CheckRight(player->GetPosition()).obj))
		{
			maze.RemoveObject(player->GetPosition());
			player->MoveRight();
			maze.PlaceObject(player);
		}

		break;
	default:
		break;
	}



	
}

void Level::HandleEnemyAI(Enemy* enemy)
{
	int input = rand() % 4;

	switch (input)
	{
	case Up:
		if (maze.CheckUp(enemy->GetPosition()).display == maze.getWallChar()) break;

		if (HandleCollision(*enemy, maze.CheckUp(enemy->GetPosition()).obj))
		{
			maze.RemoveObject(enemy->GetPosition());
			enemy->MoveUp();
			maze.PlaceObject(enemy);
			enemy->EnemyMoved();
		}
		else
		{
			enemy->CanMove();
		}
		break;
	case Down:
		if (maze.CheckDown(enemy->GetPosition()).display == maze.getWallChar()) break;

		if (HandleCollision(*enemy, maze.CheckDown(enemy->GetPosition()).obj))
		{
			maze.RemoveObject(enemy->GetPosition());
			enemy->MoveDown();
			maze.PlaceObject(enemy);
			enemy->EnemyMoved();
		}
		else
		{
			enemy->CanMove();
		}
		break;
	case Left:
		if (maze.CheckLeft(enemy->GetPosition()).display == maze.getWallChar()) break;

		if (HandleCollision(*enemy, maze.CheckLeft(enemy->GetPosition()).obj))
		{
			maze.RemoveObject(enemy->GetPosition());
			enemy->MoveLeft();
			maze.PlaceObject(enemy);
			enemy->EnemyMoved();
		}
		else
		{
			enemy->CanMove();
		}
		break;
	case Right:
		if (maze.CheckRight(enemy->GetPosition()).display == maze.getWallChar()) break;

		if (HandleCollision(*enemy, maze.CheckRight(enemy->GetPosition()).obj))
		{
			maze.RemoveObject(enemy->GetPosition());
			enemy->MoveRight();
			maze.PlaceObject(enemy);
			enemy->EnemyMoved();
		}
		else
		{
			enemy->CanMove();
		}
		break;
	default:
		break;
	}	
}

bool Level::HandleCollision(Character& c, GameObject* obj)
{
	if (obj == nullptr) 
		return true; //Can move, cell is free.
	
	//If is player, handle player collision
	Player* player = dynamic_cast<Player*>(&c);
	if (player != nullptr)
	{
		if (obj->GetSymbol() == exitDoor.GetSymbol())
		{
			NextLevel();
			return false;
		}

		Enemy* enemy = dynamic_cast<Enemy*> (obj);
		if (enemy != nullptr)
		{
			if (player->GetCanKill())
			{
				maze.RemoveObject(enemy->GetPosition());
				enemies.erase(std::remove(enemies.begin(),enemies.end(),enemy),enemies.end());
				delete enemy;
				enemy = nullptr;
				return true;
			}
			else
			{
				player->RemoveLife();
				maze.RemoveObject(player->GetPosition());
				player->SetPosition(maze.GetStartPos());
				maze.PlaceObject(player);
				return false;
			}
		}

		Coin* coin = dynamic_cast<Coin*> (obj);
		if (coin != nullptr)
		{
			player->SetScore(5);
			coins.erase(std::remove(coins.begin(), coins.end(), coin), coins.end());
			delete coin;
			coin = nullptr;
			return true;
		}

		KillFruit* killFruit = dynamic_cast<KillFruit*> (obj);
		if (killFruit != nullptr)
		{
			player->CanKill();
			killFruits.erase(std::remove(killFruits.begin(), killFruits.end(), killFruit), killFruits.end());
			delete killFruit;
			killFruit = nullptr;
			return true;
		}

		
	}

	//If enemy, handle enemy collision
	Enemy* enemy = dynamic_cast<Enemy*>(&c);
	if (enemy != nullptr)
	{
		if (obj->GetSymbol() == exitDoor.GetSymbol()) return false;

		Player* player = dynamic_cast<Player*> (obj);
		if (player != nullptr)
		{
			if (player->GetCanKill())
				return false;
			else
			{
				player->RemoveLife();
				maze.RemoveObject(player->GetPosition());
				player->SetPosition(maze.GetStartPos());
				maze.PlaceObject(player);
				return true;
			}	
		}

		Enemy* enemy = dynamic_cast<Enemy*> (obj);
		if (enemy != nullptr) return false;

		Coin* coin = dynamic_cast<Coin*> (obj);
		if (coin != nullptr) return false;

		KillFruit* killFruit = dynamic_cast<KillFruit*> (obj);
		if (killFruit != nullptr) return false;
	}
}

void Level::DeleteObjects()
{
	//Range based loops

	for (Enemy* enemy : enemies)
		delete enemy;
	enemies.clear();

	for (Coin* coin : coins)
		delete coin;
	coins.clear();

	for (KillFruit* killfruit : killFruits)
		delete killfruit;
	killFruits.clear();

}

void Level::DeleteAll()
{
	delete player;
	DeleteObjects();
}

Player* Level::GetPlayer()
{
	return player;
}



void Level::HandleEnemyMovement()
{
	for ( int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->EnemyPatrol();

		if (enemies[i]->GetCanMove()) HandleEnemyAI(enemies[i]);
	}
}

