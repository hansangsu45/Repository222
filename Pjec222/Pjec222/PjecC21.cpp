#include<iostream>
#include<WIndows.h>
#include<time.h>
using namespace std;

//스택실습 2
typedef struct Position
{
	int x;
	int y;
	int d;
}Position;

typedef struct Mtable
{
	int x;
	int y;
}Mtable;

int Maze[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,1,1,1,1,0,1},
	{1,1,0,1,1,1,1,0,0,1},
	{1,1,0,1,1,0,1,0,1,1},
	{1,0,0,1,1,0,1,0,1,1},
	{1,1,0,0,0,0,0,0,1,1},
	{1,1,0,0,1,0,1,1,1,1},
	{1,1,0,0,1,1,1,0,0,1},
	{1,1,1,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1},
};

int Maze2[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,1,1,0,1,1},
	{1,1,0,0,0,1,0,0,1,1},
	{1,1,0,1,1,1,1,0,1,1},
	{1,0,0,1,1,1,1,0,1,1},
	{1,1,0,0,0,0,0,0,1,1},
	{1,1,0,0,1,1,1,1,1,1},
	{1,1,0,0,1,1,1,0,0,1},
	{1,1,1,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1},
};

int Maze3[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,1,1},
	{1,1,0,0,1,0,0,0,1,1},
	{1,1,0,1,1,0,1,0,0,1},
	{1,0,0,1,1,0,1,0,1,1},
	{1,0,0,0,0,0,0,0,1,1},
	{1,0,1,0,1,0,1,1,1,1},
	{1,0,0,0,1,0,1,0,0,1},
	{1,1,1,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1},
};

int MainMaze[10][10];

Mtable Move[4] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

int Mark[10][10];
int top;
Position Trace[8 * 8];

void ShowMaze(Position p)
{
	int i, j;

	Sleep(50);
	system("cls");

	cout << "출구: (7,8)" << endl;

	cout << "현재 좌표: " << p.x << " " << p.y << " " << p.d << endl;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (MainMaze[i][j] == 1) cout << "#";
			else if (p.x == i && p.y == j) cout << "&";
			else cout << " ";
		}
		cout << endl;
	}
}

void Push(Position p)
{
	Trace[top].x = p.x;
	Trace[top].y=p.y;
	Trace[top].d=p.d;
	top++;
}

void Pop(Position* p)
{
	top--;
	p->x = Trace[top].x;
	p->y = Trace[top].y;
	p->d = Trace[top].d;
}

int main()
{
	//랜덤 미로 맵(보너스 문제)
	srand((unsigned int)time(NULL));
	int ran = rand() % 3;
	if (ran == 0) memcpy(MainMaze, Maze, sizeof(Maze));
	else if(ran==1) memcpy(MainMaze, Maze2, sizeof(Maze2));
	else if (ran == 2) memcpy(MainMaze, Maze3, sizeof(Maze3));

	int isFound = false;
	int i, dir;

	Position Now = { 1,1,0 };
	Position Next;

	Push(Now);

	while (!isFound && top > 0)
	{
		Pop(&Now);
		dir = Now.d;

		while (dir < 4)
		{
			Next.x = Now.x + Move[dir].x;
			Next.y = Now.y + Move[dir].y;

			if (Next.x == 7 && Next.y == 8)
			{
				Next.d = dir;
				Push(Next);
				isFound = true;
				break;
			}
			else if ((MainMaze[Next.x][Next.y] == 0) && (Mark[Next.x][Next.y] == 0))
			{
				Now.d = ++dir;
				Push(Now);

				Now.x = Next.x;
				Now.y = Next.y;
				dir = 0;

				Mark[Next.x][Next.y] = 1;
			}
			else dir++;

			ShowMaze(Now);
		}
	}
		if (isFound)
		{
			for (i = 0; i < top; i++)
			{
				ShowMaze(Trace[i]);
			}
		}
		else cout << "Not Found!" << endl;

		system("pause");
		return 0;
	
}