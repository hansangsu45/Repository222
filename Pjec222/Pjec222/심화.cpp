#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<math.h>
using namespace std;

#define DINO_BOTTOM_Y 12
#define DINO_TOP_Y 1
#define TREE_BOTTOM_X 45
#define TREE_BOTTOM_Y 20
#define BULLET_BOTTOM_Y 20
#define BULLET_BOTTOM_X 5
#define BIRD_BOTTOM_X 45
#define BIRD_BOTTOM_Y 4
#define BULLET2_YPOS 11

bool bLegFlag;

void gotoXY(int x, int y)
{
    HANDLE hOut;
    COORD Cur;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Cur.X = x * 2;
    Cur.Y = y;
    SetConsoleCursorPosition(hOut, Cur);
}

void clrscr()
{
    system("cls");
}

void setConsoleView()
{
    system("mode con:cols=100 lines=25");
    system("title °ø·æ °ÔÀÓ");
}

void drawDino(int posY)
{
    gotoXY(0, posY);
    cout << "        $$$$$$$ " << endl;
    cout << "       $$ $$$$$$" << endl;
    cout << "       $$$$$$$$$" << endl;
    cout << "$      $$$      " << endl;
    cout << "$$     $$$$$$$  " << endl;
    cout << "$$$   $$$$$     " << endl;
    cout << " $$  $$$$$$$$$$ " << endl;
    cout << " $$$$$$$$$$$    " << endl;
    cout << "  $$$$$$$$$$    " << endl;
    cout << "    $$$$$$$$    " << endl;
    cout << "     $$$$$$     " << endl;

    if (bLegFlag) {
        cout << "     $    $$$   " << endl;
        cout << "     $$         ";
    }
    else {
        cout << "     $$$  $     " << endl;
        cout << "          $$    ";
    }
    bLegFlag = !bLegFlag;
}

void drawTree(int posX)
{
    gotoXY(posX, TREE_BOTTOM_Y);
    cout << "$$$$";
    gotoXY(posX, TREE_BOTTOM_Y + 1);
    cout << " $$ ";
    gotoXY(posX, TREE_BOTTOM_Y + 2);
    cout << " $$ ";
    gotoXY(posX, TREE_BOTTOM_Y + 3);
    cout << " $$ ";
    gotoXY(posX, TREE_BOTTOM_Y + 4);
    cout << " $$ ";
}

void drawScore(int s)
{
    gotoXY(40, 2);
    cout << "Score: " << s;
}

void drawBullet(int posX)
{
    gotoXY(posX, BULLET_BOTTOM_Y);
    cout << "$$$$";
    gotoXY(posX, BULLET_BOTTOM_Y + 1);
    cout << "$$$$$";
    gotoXY(posX, BULLET_BOTTOM_Y + 2);
    cout << "$$$$";
}

void drawBird(int posX)
{
    gotoXY(posX, BIRD_BOTTOM_Y);
    cout << "     $";
    gotoXY(posX, BIRD_BOTTOM_Y+1);
    cout << "  $$$";
    gotoXY(posX, BIRD_BOTTOM_Y + 2);
    cout << "$$$$$";
    gotoXY(posX, BIRD_BOTTOM_Y + 3);
    cout << "  $$$";
    gotoXY(posX, BIRD_BOTTOM_Y+4);
    cout << "     $";
}

void drawBullet2(int posY)
{
    gotoXY(0, posY);
    cout << " $$ "<<endl;
    cout << "$$$$"<<endl;
    cout << "$$$$";
}

void drawGameover()
{
    gotoXY(10, 10);
    cout << "GAME OVER!!";
}

int k = 0;

int getKeyDown()
{
    if (_kbhit() != 0)
    {
        k = _getch();
    }
    return 0;
}

int main()
{
    bLegFlag = false;

    bool isJumping = false;
    bool isBotton = true;
    bool isGameover = false;
    bool isAtk = false, isAtk2 = false;
    const int gravity = 3;

    int score = 0;
    int dinoY = DINO_BOTTOM_Y;
    int treeX = TREE_BOTTOM_X;
    int bulletX = BULLET_BOTTOM_X;
    int birdX = BIRD_BOTTOM_X;
    int bulletY = BULLET2_YPOS;

    setConsoleView();

    int t;

    while (true)
    {
        t = getKeyDown();
        if (k == 'a')
        {
            if (!isAtk)
            {
                isAtk = true;
            }
        }
        if (k == 'j' && isBotton && !isGameover)
        {
            isJumping = true;
            isBotton = false;
        }
        if (k == 'u')
        {
            if (!isAtk2)
            {
                isAtk2 = true;
            }
        }

        k = 0;

        if (treeX <= 6 && dinoY >= DINO_BOTTOM_Y - 4)
        {
            isGameover = true;
        }
        if (isAtk)
        {
            if (abs(bulletX - treeX) <= 2)
            {
                treeX = TREE_BOTTOM_X;
                bulletX = BULLET_BOTTOM_X;
                isAtk = false;
                score++;
            }
        }
        if (isAtk2)
        {
            if (abs(bulletY - (BIRD_BOTTOM_Y+2)) <= 2 && birdX<=3)
            {
                birdX = BIRD_BOTTOM_X;
                bulletY = BULLET2_YPOS;
                isAtk2 = false;
                score++;
            }
        }

        if (!isGameover)
        {
            if (isJumping)
            {
                dinoY -= gravity;
            }
            else {
                dinoY += gravity;
            }

            if (dinoY <= DINO_TOP_Y)
            {
                dinoY = DINO_TOP_Y;
                isJumping = false;
            }
            else if (dinoY >= DINO_BOTTOM_Y)
            {
                dinoY = DINO_BOTTOM_Y;
                isBotton = true;
            }

            treeX -= 2;
            birdX -= 3;
            if (treeX <= 0)
            {
                treeX = TREE_BOTTOM_X;
            }
            if (birdX <= 0)
            {
                birdX = BIRD_BOTTOM_X;
            }

            if (isAtk)
            {
                bulletX += 2;
                if (bulletX >= 30)
                {
                    bulletX = BULLET_BOTTOM_X;
                    isAtk = false;
                }
            }
            if (isAtk2)
            {
                bulletY -= 2;
                if (bulletY <= 0)
                {
                    bulletY = BULLET2_YPOS;
                    isAtk2 = false;
                }
            }
        }
        else {
            drawGameover();
        }

        drawDino(dinoY);
        drawTree(treeX);
        drawBird(birdX);
        drawScore(score);

        if (isAtk) drawBullet(bulletX);
        if (isAtk2) drawBullet2(bulletY);

        Sleep(80);
        clrscr();
    }



    return 0;
}