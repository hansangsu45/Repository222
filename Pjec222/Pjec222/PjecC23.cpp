#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

char Stage[10][16] =
{
	"+++++++++++++++",
	"+++++++++++++++",
	"++++&  ++++++++",
	"++++ OO++++++++",
	"++++ O ++++.+++",
	"++++++ ++++.+++",
	"++++++     .+++",
	"+++++    +  +++",
	"+++++    ++++++",
	"+++++++++++++++"
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

void clrscr()
{
	system("cls");
}

char backgroundMap[10][16];
int currentX, currentY;
int totalMove;
bool bPull;
int diy, dix;

void initScreen()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			gotoXY(x, y);
			_putch(backgroundMap[y][x]);
		}
	}

	gotoXY(currentX, currentY);
	_putch('&');

	gotoXY(20, 2);
	puts("PushPush");

	gotoXY(20, 4);
	puts("Q : 종료");

	gotoXY(20, 6);
	printf("이동 횟수 : %d", totalMove);



	gotoXY(20, 10);
	cout << bPull;

	gotoXY(20, 12);
	cout << dix;

	gotoXY(20, 14);
	cout << diy;
}

bool checkEnd()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (Stage[y][x] == '.' && backgroundMap[y][x] != 'O')
			{
				return false;
			}
		}
	}

	return true;
}

void move(int dir)
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
	}

	if (backgroundMap[currentY + dir_y][currentX + dir_x] != '+')
	{
		if (backgroundMap[currentY + dir_y][currentX + dir_x] == 'O')
		{
			if (backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == ' ' || backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == '.')
			{
				if (Stage[currentY + dir_y][currentX + dir_x] == '.')
				{
					backgroundMap[currentY + dir_y][currentX + dir_x] = '.';
				}
				else
				{
					backgroundMap[currentY + dir_y][currentX + dir_x] = ' ';
				}

				backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] = 'O';
			}
			else
			{
				return;
			}
		}

		if (bPull)
		{
			if (backgroundMap[currentY + diy + dir_y][currentX + dix + dir_x] == '+'
				|| backgroundMap[currentY + diy + dir_y][currentX + dix + dir_x] == 'O') return;

			if (Stage[currentY + diy][currentX + dix] == '.')
			{
				backgroundMap[currentY + diy][currentX + dix] = '.';
			}
			else
			{
				backgroundMap[currentY + diy][currentX + dix] = ' ';
			}
			
			backgroundMap[currentY + diy + dir_y][currentX + dix + dir_x] = '8';
		}

		currentX = currentX + dir_x;
		currentY = currentY + dir_y;
		totalMove++;
	}
}

void pullE()
{
	bool o = false, b=false;
	dix = 0; diy = 0;

	if (backgroundMap[currentY - 1][currentX] == 'O')
	{
		o = true;
		diy = -1;
	}
	if (backgroundMap[currentY + 1][currentX] == 'O')
	{
		if (o) b = true;

		else {
			o = true;
			diy = 1;
		}
	}
	if (backgroundMap[currentY][currentX-1] == 'O')
	{
		if (o) b = true;

		else {
			o = true;
			dix = -1;
		}
	}
	if (backgroundMap[currentY][currentX+1] == 'O')
	{
		if (o) b = true;

		else {
			o = true;
			dix = 1;
		}
	}

	if (!b && o) {
		bPull = true;
		backgroundMap[currentY + diy][currentX + dix] = '8';
	}
	else {
		dix = 0;
		diy = 0;
	}
}

int main()
{
	int ch;

	memcpy(backgroundMap, Stage, sizeof(backgroundMap));

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (backgroundMap[y][x] == '&')
			{
				currentX = x;
				currentY = y;
				backgroundMap[y][x] = ' ';
			}
		}
	}

	clrscr();

	totalMove = 0;
	bPull = false;

	while (true)
	{
		initScreen();

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
				move(ch);
				break;
			}
		}
		else
		{
			ch = tolower(ch);

			if (ch == 'q')
			{
				clrscr();
				exit(0);
			}
			else if (ch == 'p')
			{
				if (bPull)
				{
					backgroundMap[currentY+diy][currentX+dix] = 'O';
					dix = 0;
					diy = 0;
					bPull = false;
				}
				else
				{
					pullE();
				}
			}
		}

		if (checkEnd())
		{
			clrscr();

			gotoXY(10, 4);
			printf("CLEAR");

			_getch();
			clrscr();
			exit(0);
			break;
		}
	}

	return 0;
}