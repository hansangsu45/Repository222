#include<iostream>
using namespace std;

int factorial(int num)  //팩토리얼 함수(재귀함수)
{
	if (num <= 1) return 1;
	return num * factorial(num - 1);
}

int factorial2(int num)  //팩토리얼 함수(재귀함수X)
{
	int sum = 1;
	for (int i = 1; i <= num; i++)
	{
		sum *= i;
	}
	return sum;
}

int GaussCalc(int n)  //가우스 계산법(공식 활용)
{
	return (n + 1) * n / 2;
}

int SumCalc(int n)  //합(공식 활용 X, 재귀함수)
{
	if (n == 1) return 1;
	return n + SumCalc(n - 1);
}

int main()
{
	//팩토리얼(재귀함수 사용)
	int num = 6;
	int n = factorial(num);
	cout << "factorial " << num << "!: " << n << endl;

	//가우스 계산법
	int num3;
	cin >> num3;
	cout << "Sum: ";
	cout << GaussCalc(num3) << endl;

	//1~100 합(가우스 X)
	int num4 = 100;
	cout << "Sum(1~100): " << SumCalc(num4) << endl;

	//팩토리얼 (재귀X)
	int num5 = 6;
	cout << "factorial " << num5 << "!: " << factorial2(num5) << endl;

	return 0;
}