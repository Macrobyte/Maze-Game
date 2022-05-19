#pragma once
#include "Pickups.h"

class Coin : public Pickups
{
protected:
	int c_value{ 5 };

public:
	Coin();
	Coin(cVector2 pos);

	int GetValue() { return c_value; }
	
};

