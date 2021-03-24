#include<iostream>
using namespace std;

int factorial(int num)  //���丮�� �Լ�(����Լ�)
{
	if (num <= 1) return 1;
	return num * factorial(num - 1);
}

int factorial2(int num)  //���丮�� �Լ�(����Լ�X)
{
	int sum = 1;
	for (int i = 1; i <= num; i++)
	{
		sum *= i;
	}
	return sum;
}

int GaussCalc(int n)  //���콺 ����(���� Ȱ��)
{
	return (n + 1) * n / 2;
}

int SumCalc(int n)  //��(���� Ȱ�� X, ����Լ�)
{
	if (n == 1) return 1;
	return n + SumCalc(n - 1);
}

int main()
{
	//���丮��(����Լ� ���)
	int num = 6;
	int n = factorial(num);
	cout << "factorial " << num << "!: " << n << endl;

	//���콺 ����
	int num3;
	cin >> num3;
	cout << "Sum: ";
	cout << GaussCalc(num3) << endl;

	//1~100 ��(���콺 X)
	int num4 = 100;
	cout << "Sum(1~100): " << SumCalc(num4) << endl;

	//���丮�� (���X)
	int num5 = 6;
	cout << "factorial " << num5 << "!: " << factorial2(num5) << endl;

	return 0;
}