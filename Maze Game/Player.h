#pragma once
#include "Character.h"

class Player : public Character
{
protected:
	clock_t killTimer = clock();
	const int killTime = 12000;

	int p_lives{ 0 };
	int p_score{ 0 };
	bool canKill{ false };


public:
	Player();
	~Player();

	void SetScore(int score);
	int GetScore();

	int GetLives();
	void SetLives(int lives);
	void RemoveLife();

	bool GetCanKill();
	void CanKill();
	void KillTimer();

	int GetKillTimer();

};

