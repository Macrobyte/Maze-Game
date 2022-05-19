#include "Coin.h"

Coin::Coin()
{
	obj_symbol = char(254);
	obj_color = Bright_Yellow;
}

Coin::Coin(cVector2 pos)
{
	obj_symbol = char(254);
	obj_color = Bright_Yellow;
	position = pos;
}
