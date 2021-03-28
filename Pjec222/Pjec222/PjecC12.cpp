#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> va;
	vector<int> vb;
	int n;
	cin >> n;
	int l = n;
	
	for (int i = 0; i < l; i++)
	{
		cin >> n;
		va.push_back(n);
	}
	for (int i = 0; i < l; i++)
	{
		cin >> n;
		vb.push_back(n);
	}

	sort(va.begin(), va.end(), greater<int>());
	sort(vb.begin(), vb.end());

	int sum=0;
	for (int i = 0; i < l; ++i)
	{
		sum += va[i] * vb[i];
	}

	cout << sum << endl;
}