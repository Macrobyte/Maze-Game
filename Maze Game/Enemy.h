#pragma once
#include "Character.h"

class Enemy : public Character
{
protected:
	clock_t moveTimer = clock();
	bool canMove;

public:
	Enemy();
	Enemy(cVector2 spawnPos);
	~Enemy();

	void EnemyPatrol();
	void EnemyMoved();
	void CanMove();
	bool GetCanMove();


};

