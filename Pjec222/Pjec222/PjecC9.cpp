#include<iostream>
using namespace std;

int rad=1;

int Fibo(int n)  //�Ǻ���ġ ���� �Լ�
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

void HanoiTower(int num, char from, char by, char to)  //�ϳ��� ž �Լ�
{
	if (num == 1)  //�̵��� ���� 1��
		cout << "���� 1��" << from << "����" << to << "�� �̵�" << endl;
	else {
		//3�ܰ� �� 1�ܰ�
		HanoiTower(num - 1, from, to, by);
		//3�ܰ� �� 2�ܰ�
		cout << "���� " << num<<"��(��)" << from<< "����" << to << "�� �̵�" << endl;
		//3�ܰ� �� 3�ܰ�
		HanoiTower(num - 1, by, from, to);
	}
}

int SumCalc(int n)  //1~n���� ��(����Լ� ���)
{
	if (n == 1) return 1;
	return n + SumCalc(n - 1);
}

int N_Reverse(int n) //�Է¹��� �������� �Ųٷ� ���(����Լ� ���)
{
	if (n == 0) return 0;
	int result = N_Reverse(n / 10) + (n % 10) * rad;
	rad *= 10;
	return result;
}

int main()
{
	//�Ǻ���ġ ����
	cout << "���� �Է�: ";
	int num2;
	cin >> num2;

	cout << "Fibo: ";
	for (int i = 1; i <= num2; i++)
		cout << Fibo(i) << " ";
	cout << endl<<endl;

	//�ϳ��� ž
	cout << "�ϳ��� ž" << endl;
	HanoiTower(3, 'A', 'B', 'C');
	cout << endl << endl;

	//1~n��
	cout << "���� �Է�: ";
	int a;
	cin >> a;
	cout<<"1~"<<a<<"������ ��: "<<SumCalc(a) << endl<<endl;

	//�Է¹��� �������� �Ųٷ� ���
	cout << "���� �Է�: ";
	int b;
	cin >> b;
	cout <<b<<"�� �Ųٷ� ���--> " <<N_Reverse(b) << endl;
}