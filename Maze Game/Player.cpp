#include "Player.h"

Player::Player()
{
	obj_symbol = char(2);
	obj_color = Bright_Green;
}

Player::~Player()
{
}

void Player::SetScore(int score)
{
	p_score += score;
}

int Player::GetScore()
{
	return p_score;
}

void Player::RemoveLife()
{
	p_lives--;
}

int Player::GetLives()
{
	return p_lives;
}

void Player::SetLives(int lives)
{
	p_lives = lives;
}

bool Player::GetCanKill()
{
	return canKill;
}

void Player::CanKill()
{
	canKill = true;
	killTimer = clock();
}

void Player::KillTimer()
{
	if (canKill)
	{
		if (killTimer + killTime < clock())
		{
			canKill = false;
			
		}
	}
	
}

int Player::GetKillTimer()
{
	return (int)((killTimer + killTime) - clock())/CLOCKS_PER_SEC;
}
