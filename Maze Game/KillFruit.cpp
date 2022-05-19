#include "KillFruit.h"

KillFruit::KillFruit()
{
	obj_symbol = char(254);
	obj_color = Magenta;
}

KillFruit::KillFruit(cVector2 pos)
{
	obj_symbol = char(254);
	obj_color = Magenta;
	position = pos;
}
