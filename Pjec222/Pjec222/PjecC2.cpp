#include<iostream>
using namespace std;

int main()
{
	int year = 2021;
	int y;
	cout << "주민번호를 입력하세요." << endl;
	char arr[14];
	cin >> arr;

	string s;
	if (arr[6] % 2 == 1) s = "남자";
	else if (arr[6] % 2 == 0) s = "여자";

	y = (arr[0] - 48) * 10 + (arr[1] - '0');
	if (arr[6] == '1' || arr[6] == '2') y += 1900;
	else if (arr[6] == '3' || arr[6] == '4') y += 2000;

	cout << "성별: " << s << endl;
	cout << "나이: " << year - y + 1 << endl;
	cout << "출생 연도: " << y << endl;

	int b = (arr[7] - 48) * 10 + (arr[8] - '0');
	string t;
	int arr2[11] = { 8,12,15,18,25,34,39,47,54,66,90 };
	for (int i = 0; i < 11; i++)
	{
		if (b <= arr2[i])
		{
			if (i == 0) t = "서울";
			else if (i == 1) t == "부산";
			else if (i == 2) t == "인천";
			else if (i == 3) t = "경기도 주요 도시";
			else if (i == 4) t = "그 밖의 경기도";
			else if (i == 5) t = "강원도";
			else if (i == 6) t = "충청북도";
			else if (i == 7) t = "충청남도";
			else if (i == 8) t = "전라북도";
			else if (i == 9) t = "전라남도";
			else if (i == 10) t = "경상도";
			break;
		}
	}
	cout << "출생 지역: " << t << endl;

	int arr3[] = { 2,3,4,5,6,7,8,9,2,3,4,5 };
	int sum = 0;

	for (int i = 0; i < 12; i++)
	{
		sum += (arr[i] - '0') * arr3[i];
	}

	sum %= 11;
	sum = (11 - sum) % 10;

	if (sum == arr[12] - '0') cout << "주민등록번호가 유효함";
	else cout << "주민등록번호가 유효하지않음";
}