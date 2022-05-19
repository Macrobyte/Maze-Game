#include "Enemy.h"

Enemy::Enemy()
{
	obj_symbol = char(1);
	obj_color = Bright_Red;
}

Enemy::Enemy(cVector2 spawnPos)
{
	position = spawnPos;
	obj_symbol = char(1);
	obj_color = Bright_Red;
}

Enemy::~Enemy()
{
}

void Enemy::EnemyPatrol()
{
	int rTime = rand() % 500 + 1000;

	if (canMove == false)
	{
		if (moveTimer + rTime < clock())
		{
			canMove = true;
			moveTimer = clock();
		}
	}
		
}

void Enemy::EnemyMoved()
{
	canMove = false;	
}

void Enemy::CanMove()
{
	canMove = true;
}

bool Enemy::GetCanMove()
{
	return canMove;
}
