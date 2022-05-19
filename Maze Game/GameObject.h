#pragma once
#include "cVector2.h"

class GameObject
{
protected:
	
	enum Colors
	{
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Yellow = 6,
		White = 7,
		Gray = 8,
		Bright_Blue = 9,
		Bright_Green = 10,
		Bright_Cyan = 11,
		Bright_Red = 12,
		Bright_Magenta = 13,
		Bright_Yellow = 14,
		Bright_White = 15
	};
	cVector2 position{ 0,0 };
	char obj_symbol{ char(228) }; //Default char in case the object does not have one assigned.
	int obj_color{ White }; //Default color is white.

public:

	GameObject();

	virtual char GetSymbol();
	int GetColor() { return obj_color; }

	void SetSymbol(char newSymbol);

	void SetPosition(cVector2 newPos) ;
	cVector2 GetPosition() { return position; }
};