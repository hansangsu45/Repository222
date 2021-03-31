#include<iostream>
using namespace std;

void Sequence(int n)
{
	if (n == 0) return;

	cout << n << " ";
	Sequence(n - 1);
}

void oddNum(int a,int b)
{
	if (a > b) {
		int t = a;
		a = b;
		b = t;
	}
	int k = a % 2 == 1 ? a + 2 : a + 1;
	if (k >= b) return;
	cout << k << " ";
	oddNum(k, b);
}

void evenNum(int a, int b)
{
	if (a > b) {
		int t = a;
		a = b;
		b = t;
	}
	int k = a % 2 == 0 ? a + 2 : a + 1;
	if (k >= b) return;
	cout << k << " ";
	evenNum(k, b);
}

int main()
{
	//1~n����
	int a, b;
	cin >> a;
    Sequence(a); //n, n-1, n-2, ......., 1
	cout << endl << endl;

	//�� �� ������ Ȧ��(���̴ϱ� a�� b�� ����)
	cin >> a >> b;
	oddNum(a, b);
	cout << endl << endl<<endl;

	//�� �� ������ ¦��(���̴ϱ� a�� b�� ����)
	cin >> a >> b;
	evenNum(a, b);
	cout << endl;
}