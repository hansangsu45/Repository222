#include<iostream>
using namespace std;

int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}
//�ִ� ��� �Լ�
int MaxValue(int arr[], int l)
{
	if (l == 1) return arr[0];
	else return max(arr[l - 1], MaxValue(arr, l - 1));
}

const int p = 10;
int t;
int sum(int a)  //�� �ڸ� �� �� �Լ�
{
	if (a == 0) return 0;
	else {
		int q = a % p;
		t /= 10;
		return q+sum(t);
	}
}

void Mul(int a)  //������ �Լ�
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
	//�ִ� ���
	cout << "���� �Է�(5��): ";
	int arr[5];
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) cin >> arr[i];
	cout << "�ִ�: " << MaxValue(arr, sizeof(arr) / sizeof(int)) << endl << endl;

	//�� �ڸ��� ��
	cout << "���� �Է�: ";
	int a; 
	cin >> a;
	t = a;
	cout << "�� �ڸ����� ��: " << sum(t) << endl<<endl;

	//������
	int n = 2;
	Mul(n);
}