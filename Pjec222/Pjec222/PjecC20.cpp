#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	int answer[3] = { 0, };

	answer[0] = rand() % 9 + 1;

	do {
		answer[1] = rand() % 9 + 1;
	} while (answer[0] == answer[1]);

	do {
		answer[2] = rand() % 9 + 1;
	} while (answer[0] == answer[2] || answer[1] == answer[2]);

	int input[3] = { 0, };

	while (true)
	{
		int s = 0, b = 0;
		cin >> input[0] >> input[1] >> input[2];

		cout << input[0] << " : " << input[1] << " : " << input[2] << endl;
		cout << answer[0] << " : " << answer[1] << " : " << answer[2] << endl;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (input[j] == answer[i])
				{
					if (i == j) s++;
					else b++;
				}
			}
		}

		if (s == 0 && b == 0)
		{
			cout << "Out" << endl;
		}
		else if (s == 0 && b != 0) {
			cout << b << "B " << endl;
		}
		else if (s != 0 && b == 0)
		{
			cout << s << "S" << endl;
		}
		else {
			cout << b << "B, " << s << "S" << endl;
		}
	}

	return 0;
}