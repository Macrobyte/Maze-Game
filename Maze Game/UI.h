#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
class UI
{
protected:

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	char input = ' ';

public:
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
	enum KeyCodes
	{
		ArrowUp = 72, ArrowDown = 80, ArrowRight = 77, ArrowLeft = 75, Esc = 27
	};

	UI();

	template<class Message>
	void Print(short x, short y, Message message, int color = White);

	void SetCursor(short x, short y);

	void SetTextColor(int color);

	void ClearScreen();

	int GameMenu();
	int GameOverMenu();

};

template<class Message>
inline void UI::Print(short x, short y, Message message,int color)
{
	COORD coord = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	SetTextColor(color);

	std::cout << message;
}
