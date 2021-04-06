#include<iostream>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<Windows.h>
using namespace std;

const int Tone[8] = { 523,587,659,698,784,880,988,1046 };
const string name[8] = { "도","레","미","파","솔","라","시","도(높음)" };
int d=700;

int main()
{
	int SelectTone = 0;
	int Select = 0;
	cout << "절대 음감 게임" << endl << endl<<"아무 키나 누르면 시작"<<endl << endl;
	_getch();

	srand((unsigned int)time(NULL));

	while (1)
	{
		for (int i = 0; i < 8; i++)
		{
			cout << name[i] << "(" << i + 1 << ") ";
		}
		for (int i = 0; i < 8; i++)
		{
			Beep(*(Tone + i), d);
		}
		cout << endl<<endl;
		Sleep(1000);
		SelectTone = rand() % 8;
		Beep(*(Tone + SelectTone), d);
		cout << "시작" << endl;

		Select = _getch() -'1';
		if (SelectTone == Select)
		{
			cout << "맞춤\n";
		}
		else {
			cout << "틀림\n";
			cout << "정답: " << name[SelectTone] << endl;
		}
		cout << endl;
		Sleep(1000);
	}
}
