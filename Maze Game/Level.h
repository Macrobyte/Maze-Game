#pragma once
#include "Player.h"
#include "cMaze.h"
#include "Enemy.h"
#include "Coin.h"
#include "KillFruit.h"

#include<vector>

class Level
{
protected:
	enum KeyCodes
	{
		ArrowUp = 72, ArrowDown = 80, ArrowRight = 77, ArrowLeft = 75
	};

	enum Directions
	{
		Up,Down,Left,Right
	};

	cMaze maze;

	Player* player{ nullptr };

	const int enemyQty{ 3 };
	std::vector<Enemy*> enemies;
	
	const int coinQty{ 4 };
	std::vector<Coin*> coins;

	const int killFruitQty{ 4 };
	std::vector<KillFruit*> killFruits;
	
	GameObject exitDoor;

private:

	void HandleEnemyAI(Enemy* enemy);
	bool HandleCollision(Character& c, GameObject* obj);
	void DeleteObjects();
	void DeleteAll();


public:
	Level();
	~Level();

	void CreateLevel();
	void NextLevel();
	void GameOver();

	void HandlePlayerMovement(char input);
	void HandleEnemyMovement();

	Player* GetPlayer();
};

