#include<iostream>
using namespace std;

int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}
//최댓값 출력 함수
int MaxValue(int arr[], int l)
{
	if (l == 1) return arr[0];
	else return max(arr[l - 1], MaxValue(arr, l - 1));
}

const int p = 10;
int t;
int sum(int a)  //각 자리 수 합 함수
{
	if (a == 0) return 0;
	else {
		int q = a % p;
		t /= 10;
		return q+sum(t);
	}
}

void Mul(int a)  //구구단 함수
{
	if (a == 10) return;
	for (int i = 1; i < 10; i++)
	{
		cout << a << " * " << i << " = " << a * i<<endl;
	}
	Mul(a + 1);
}

int main()
{
	//최댓값 출력
	cout << "숫자 입력(5개): ";
	int arr[5];
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) cin >> arr[i];
	cout << "최댓값: " << MaxValue(arr, sizeof(arr) / sizeof(int)) << endl << endl;

	//각 자리수 합
	cout << "숫자 입력: ";
	int a; 
	cin >> a;
	t = a;
	cout << "각 자리수의 합: " << sum(t) << endl<<endl;

	//구구단
	int n = 2;
	Mul(n);
}