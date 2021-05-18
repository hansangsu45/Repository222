#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include<time.h>

using namespace std;

vector<string> pastWord;
vector<string> strWords;

void gotoXY(int x, int y)
{
	COORD cur;
	cur.X = x * 2;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

int getKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}

	return 0;
}

void setConsoleView()
{
	system("mode con:cols=50 lines=20");
	system("title WORD GAME");
}

void drawReadyGame()
{
	system("cls");
	gotoXY(5, 2);
	cout << "==================================";
	gotoXY(5, 3);
	cout << "=========== WORD GAME ============";
	gotoXY(5, 4);
	cout << "==================================";
	gotoXY(6, 6);
	cout << "시작하려면 's'를 누르세요.";
	gotoXY(20, 18);
}

bool readyGame()
{
	drawReadyGame();

	while (1)
	{
		int key = getKeyDown();
		key = tolower(key);

		if (key == 's')
		{
			return true;
		}
	}

	return false;
}

void setWords() 
{
	string str[4] = { "apple","banana","code","program" };
	
	ifstream readFromFile("words.txt");

	if (!readFromFile.is_open())
	{
		ofstream writeToFile("words.txt");

		for (int i = 0; i < 4; i++) {
			string temp = str[i];
			if (i < 3) {
				temp += "\n";
			}
			writeToFile.write(temp.c_str(), temp.size());
			strWords.push_back(str[i]);
		}
		
		writeToFile.close();
	}
	else {
		while (!readFromFile.eof())
		{
			string temp;
			getline(readFromFile, temp);
			strWords.push_back(temp);
		}
	}

	readFromFile.close();
}

void drawStartGame()
{
	system("cls");
	gotoXY(5, 8);
	cout << "past = ";
	for (int i = 0; i < (int)pastWord.size(); ++i)
	{
		cout << pastWord[i] << " ";
	}

	gotoXY(5, 12);
	cout << "input = ";
}

void startGame()
{
	setWords();

	while (1) {
		int num = rand() % (int)strWords.size();
		string strOriginal = strWords[num];
		int originalLen = (int)strOriginal.length();

		string strQuestion;
		for (int i = 0; i < originalLen; i++) {
			strQuestion += "_";
		}

		while (1) {
			drawStartGame();

			gotoXY(5, 5);
			for (int i = 0; i < originalLen; i++) {
				cout << strQuestion[i] << " ";
			}
			cout << endl;

			bool isSame = false;
			gotoXY(9, 12);
			string strInput;
			cin >> strInput;

			if (strInput.length() == 1)
			{
				for (int i = 0; i < originalLen; i++) {
					if (strOriginal[i] == strInput[0]) {
						strQuestion[i]=strInput[0];
					}
				}
				for (int i=0; i<pastWord.size(); i++)
				{
					if (pastWord[i] == strInput) {
						isSame=true;
					}
				}
				if(!isSame) pastWord.push_back(strInput);
			}
			else if (strInput.length() > 1)
			{
				if (strOriginal == strInput) {
					pastWord.clear();
					break;
				}
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	setConsoleView();

	while (true)
	{
		if (readyGame())
		{
			startGame();
		}
	}

	return 0;
}