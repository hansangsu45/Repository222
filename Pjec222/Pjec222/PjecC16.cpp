#include<iostream>
using namespace std;

int main()
{
	
	int n, count=0, one, ten, hun;
	cin >> n;  //  1 <= n <= 1000 (ÀÚ¿¬¼ö)

	for (int i = 1; i <= n; ++i)
	{
		if (i < 100)
		{
			count++;
		}
		else if(i<1000)
		{
			one = i % 10;
			ten = (i % 100)/10;
			hun = i / 100;
			if (hun - ten == ten - one) count++;
		}
	}

	cout << endl << count << endl;
}