#include<iostream>
#include<string>
using namespace std;

int main()  //�Է� ���� �� ���� ������ 0~9���� ���� ���� Ƚ��
{
	//100~999,  �� �� ���� �ִ� 997002999, �ּڰ� 1000000 
	int a, b, c;
	cin >> a >> b >> c;
	cout << endl;
	cout << a * b * c << endl;  //Ȯ�ο� �ڵ�

	int m = a * b * c;
	int arr[10] = {0,}; //0~9���� ���� ���� �迭
	string s = to_string(m);
	
	for (int i = 0; i < s.size(); ++i)
	{
		arr[s[i] - 48]++;
	}

	for (int i = 0; i < 10; ++i)
		cout << i << "�� ����: " << arr[i] << endl;
}