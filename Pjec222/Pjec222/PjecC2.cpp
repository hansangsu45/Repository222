#include<iostream>
using namespace std;

int main()
{
	int year = 2021;
	int y;
	cout << "�ֹι�ȣ�� �Է��ϼ���." << endl;
	char arr[14];
	cin >> arr;

	string s;
	if (arr[6] % 2 == 1) s = "����";
	else if (arr[6] % 2 == 0) s = "����";

	y = (arr[0] - 48) * 10 + (arr[1] - '0');
	if (arr[6] == '1' || arr[6] == '2') y += 1900;
	else if (arr[6] == '3' || arr[6] == '4') y += 2000;

	cout << "����: " << s << endl;
	cout << "����: " << year - y + 1 << endl;
	cout << "��� ����: " << y << endl;

	int b = (arr[7] - 48) * 10 + (arr[8] - '0');
	string t;
	int arr2[11] = { 8,12,15,18,25,34,39,47,54,66,90 };
	for (int i = 0; i < 11; i++)
	{
		if (b <= arr2[i])
		{
			if (i == 0) t = "����";
			else if (i == 1) t == "�λ�";
			else if (i == 2) t == "��õ";
			else if (i == 3) t = "��⵵ �ֿ� ����";
			else if (i == 4) t = "�� ���� ��⵵";
			else if (i == 5) t = "������";
			else if (i == 6) t = "��û�ϵ�";
			else if (i == 7) t = "��û����";
			else if (i == 8) t = "����ϵ�";
			else if (i == 9) t = "���󳲵�";
			else if (i == 10) t = "���";
			break;
		}
	}
	cout << "��� ����: " << t << endl;

	int arr3[] = { 2,3,4,5,6,7,8,9,2,3,4,5 };
	int sum = 0;

	for (int i = 0; i < 12; i++)
	{
		sum += (arr[i] - '0') * arr3[i];
	}

	sum %= 11;
	sum = (11 - sum) % 10;

	if (sum == arr[12] - '0') cout << "�ֹε�Ϲ�ȣ�� ��ȿ��";
	else cout << "�ֹε�Ϲ�ȣ�� ��ȿ��������";
}