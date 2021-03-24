#include<iostream>
using namespace std;

int factorial(int num)
{
	if (num <= 1) return 1;
	return num * factorial(num - 1);
}

int Fibo(int n)
{
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		return Fibo(n - 1) + Fibo(n - 2);
	}
}

int GaussCalc(int n)
{
	return (n + 1) * n / 2;
}

int main()
{
	//팩토리얼(재귀함수 사용)
	int num = 6;
	int n = factorial(num);

	cout << "factorial " << num << "!: " << n << endl;
	system("pause");

	//피보나치 수열(재귀함수 사용)
	int num2;
	cin >> num2;

	for (int i = 1; i <= num2; i++)
		cout << Fibo(i) << " ";
	cout << endl;

	//가우스 계산법
	int num3;
	cin >> num3;
	cout << GaussCalc(num3) << endl;

	return 0;
}