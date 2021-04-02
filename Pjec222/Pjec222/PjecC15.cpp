#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1, v2;
	int count;
	int input;
	int i, j, k, t;
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
		//cout << "n: " << n << endl;
		if (n >= max)
		{
			max = n;
		}

		n = 0;
		t = v1[count - 1];

		for (k = 0; k < v1.size()-1; k++)
		{
			v1[count-1-k] = v1[count-2-k];
		}
		v1[0] = t;

		/*for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
			cout << *it << " ";
		cout << endl;*/
	}

	cout << max << endl;
}