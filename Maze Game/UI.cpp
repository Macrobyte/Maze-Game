#include "UI.h"

UI::UI()
{
}

void UI::SetCursor(short x, short y)
{
	COORD coord = { x , y };
	SetConsoleCursorPosition(hOut, coord);
}

void UI::SetTextColor(int color)
{
	SetConsoleTextAttribute(hOut, color);
}

void UI::ClearScreen()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hOut, &info);
	DWORD d = info.srWindow.Bottom * info.srWindow.Right;
	COORD coord = { 0,0 };
	FillConsoleOutputCharacter(hOut, ' ', d, coord, &d);
}

int UI::GameMenu()
{
	std::cout << "----Main Menu----" << std::endl;
	std::cout << "1. Start Game  " << std::endl;
	std::cout << "2. Quit Game   " << std::endl;
	
	std::cin >> input;
	return input ;
	
}

int UI::GameOverMenu()
{
	SetTextColor(Red);
	std::cout << "   Game Over!   " << std::endl;
	SetTextColor(White);
	std::cout << "1. Restart Game " << std::endl;
	std::cout << "2. Quit Game  " << std::endl;

	std::cin >> input;
	return input;
}


