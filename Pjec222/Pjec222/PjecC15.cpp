#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1, v2;
	int count;
	int input;
	int i, j;
	int max=0;
	int n=0;

	cin >> count;  //원소의 개수

	for (i = 0; i < count; i++)
	{
		cin >> input;
		v1.push_back(input);
	}

	for (i = 0; i < count; ++i) {
		cin >> input;
		v2.push_back(input);
	}

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count; ++j)
		{
			n += v1[j] * v2[j];
		}
		if (n >= max)
		{
			max = n;
		}
		n = 0;
		int temp = v1[0];
		v1[0] = v1[count - 1];
		v1[count - 1] = temp;
	}

	cout << max << endl;
}