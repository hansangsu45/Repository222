#include<iostream>
#include<conio.h>
#include <Windows.h>
#include<time.h>
using namespace std;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int currentX, currentY;
bool isObs = false;

char ShowMap[22][23] = {
	"++++++++++++++++++++++",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"++++++++++++++++++++++"
};

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void _obstacle()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		ShowMap[rand() % 20 + 1][rand() % 20 + 1] = '+';
	}
}

void DispScreen()
{
	if (!isObs) {
		_obstacle();
		isObs = true;
	}

	int x, y;
	for (y = 0; y < 22; y++)
	{
		for (x = 0; x < 22; x++)
		{
			gotoXY(x, y);
			_putch(ShowMap[y][x]);
		}
	}
	gotoXY(currentX, currentY);
	_putch('0');
	gotoXY(25, 2);
	cout << "Q:Á¾·á";
}

void Move(int dir)
{
	int dir_x = 0, dir_y = 0;

	switch (dir)
	{
	case LEFT:
		dir_x = -1;
		break;
	case RIGHT:
		dir_x = 1;
		break;
	case UP:
		dir_y = -1;
		break;
	case DOWN:
		dir_y = 1;
		break;
	case (int)'a':
		if (currentX <= 19) ShowMap[currentY][currentX + 1] = '.';
		if (currentX >= 2) ShowMap[currentY][currentX - 1] = '.';
		if (currentY <= 19) ShowMap[currentY + 1][currentX] = '.';
		if (currentY >= 2) ShowMap[currentY - 1][currentX] = '.';
		break;
	case (int)'b':
		if (currentX == 20) {
			ShowMap[currentY][currentX + 1] = ' ';
			ShowMap[currentY][0] = ' ';
		}
		if (currentX == 1) {
			ShowMap[currentY][currentX - 1] = ' ';
			ShowMap[currentY][21] = ' ';
		}
		if (currentY == 20) {
			ShowMap[currentY + 1][currentX] = ' ';
			ShowMap[0][currentX] = ' ';
		}
		if (currentY == 1) {
			ShowMap[currentY - 1][currentX] = ' ';
			ShowMap[21][currentX] = ' ';
		}
		break;
	}


	if (ShowMap[currentY + dir_y][currentX + dir_x] == '+')
	{
		return;
	}
	else if (ShowMap[currentY + dir_y][currentX + dir_x] == ' ')
	{
		if (dir == LEFT || dir == RIGHT)
		{
			currentX = dir == RIGHT ? 0 : 21;
		}
		else if (dir == UP || dir == DOWN)
		{
			currentY = dir == DOWN ? 0 : 21;
		}
		return;
	}

	currentX += dir_x;
	currentY += dir_y;
}

int main()
{
	int ch;
	currentX = currentY = 1;

	while (1)
	{
		DispScreen();
		ch = _getch();

		if (ch == 0xE0 || ch == 0)
		{
			ch = _getch();
			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				Move(ch);
				break;
			}
		}
		else if (ch == 'a' || ch == 'b') {
			Move(ch);
		}
		else {
			ch = tolower(ch);
			if (ch == 'q')
			{
				exit(0);
			}
			else if (ch == 'z')
			{
				ShowMap[currentY][currentX] = 'X';
			}
		}
	}

	return 0;
}