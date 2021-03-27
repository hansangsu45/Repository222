#include<iostream>
#include<string>
using namespace std;

int main()  //입력 받은 세 수의 곱에서 0~9까지 각각 쓰인 횟수
{
	//100~999,  세 수 곱의 최댓값 997002999, 최솟값 1000000 
	int a, b, c;
	cin >> a >> b >> c;
	cout << endl;
	cout << a * b * c << endl;  //확인용 코드

	int m = a * b * c;
	int arr[10] = {0,}; //0~9까지 개수 담을 배열
	string s = to_string(m);
	
	for (int i = 0; i < s.size(); ++i)
	{
		arr[s[i] - 48]++;
	}

	for (int i = 0; i < 10; ++i)
		cout << i << "의 개수: " << arr[i] << endl;
}