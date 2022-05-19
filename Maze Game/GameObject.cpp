#include "GameObject.h"

GameObject::GameObject()
{
}

char GameObject::GetSymbol()
{
	return obj_symbol;
}

void GameObject::SetSymbol(char newSymbol)
{
	obj_symbol = newSymbol;
}

void GameObject::SetPosition(cVector2 newPos)
{
	position = newPos;
}

