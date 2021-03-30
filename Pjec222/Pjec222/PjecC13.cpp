#include<iostream>
using namespace std;

void Sequence(int n)
{
	if (n == 0) return;

	cout << n << " ";
	Sequence(n - 1);
}

bool b = false;
int _n = 1;
int p=-1;
void Sequence2(int n)
{
	if (n > p && b) {
		b = false;
		return;
	}
	if (!b) {
		b = true;
		p = n;
	}
	cout << _n << " ";
	_n++;
	Sequence2(_n);
}

int min=-1, max=-2, min2=-3, max2=-4;
bool _dec = false, _dec2 = false;
void OddNum(int a, int b)
{
	if (min >= max && _dec)
	{
		_dec = false;
		return;
	}
	if (!_dec)
	{
		_dec = true;
		if (a < b) {
			min = a; max = b;
		}
		else {
			min = b; max = a;
		}
	}

	if (min % 2 == 1) {
		min += 2;
		if (min >= max) return;
		cout << min << " ";
		
		OddNum(min, max);
	}
	else {
		min++;
		if (min >= max) return;
		cout << min << " ";
		
		OddNum(min, max);
	}
}

void EvenNum(int a, int b)
{
	if (min2 >= max2 && _dec2)
	{
		_dec2 = false;
		return;
	}
	if (!_dec2)
	{
		_dec2 = true;
		if (a < b) {
			min2 = a; max2 = b;
		}
		else {
			min2 = b; max2 = a;
		}
	}

	if (min2 % 2 == 0) {
		min2 += 2;
		if (min2 >= max2) return;
		cout << min2 << " ";

		EvenNum(min2, max2);
	}
	else {
		min2++;
		if (min2 >= max2) return;
		cout << min2 << " ";

		EvenNum(min2, max2);
	}
}

int main()
{
	//1~n까지
	int a, b;
	cin >> a;
    Sequence(a); //n, n-1, n-2, ......., 1
	cout << endl;
	Sequence2(a); //1, 2, 3, ........, n
	cout << endl << endl;

	//두 수 사이의 홀수(사이니까 a와 b는 제외)
	cin >> a >> b;
	OddNum(a, b);
	cout << endl << endl<<endl;

	//두 수 사이의 짝수(사이니까 a와 b는 제외)
	cin >> a >> b;
	EvenNum(a, b);
	cout << endl;
}