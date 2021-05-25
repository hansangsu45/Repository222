#include "Console.h"
#include "Missile.h"
#include<math.h>

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clrscr()
{
	system("cls");
}

void beep(int tone, int delay)
{
	Beep(tone, delay);
}

int getKeyDown()
{
	if (_kbhit() != 0) {
		return _getch();
	}

	return 0;
}

bool checkCollision(Missile a, Missile b)
{
	if (a.getY() == b.getY())
	{
		if (abs(a.getX() - b.getX()) < 2) return true;
	}
	
	return false;
}