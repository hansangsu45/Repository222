#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

int GetKey(void)
{
	int ch = _getch();
	if (ch == 0 || ch == 324)
	{
		ch = _getch();
	}
	return ch;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(bool show)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void MapDraw()
{
	for (int i = 0; i < 40; i++)
		cout << "■";
	cout << endl;
	for (int k = 0; k < 25; k++) {
		for (int j = 0; j < 40; j++)
		{
			if (j == 0 || j == 39)
				cout << "■";
			else
				cout << "  ";
		}
		cout << endl;
	}
	for (int t = 0; t < 40; t++)
		cout << "■";
}

int main()
{

	MapDraw();

	int key;
	int x = 5, y = 5;
	CursorView(false);
	while (1)
	{
		key = GetKey();

		if (key == 75) { if (x > 0) x = x - 1; } //좌 방향키
		else if (key == 77) { if (x < 20) x = x + 1; } //우 방향키
		else if (key == 72) { if (y > 0) y = y - 1; } //상 방향키
		else if (key == 80) { if (y < 10) y = y + 1; } //하 방향키

		Sleep(100);  //0.1초 대기(100밀리초)
		system("cls"); //화면 클리어
		MapDraw();
		gotoxy(x, y); cout << "◎";
	}
}