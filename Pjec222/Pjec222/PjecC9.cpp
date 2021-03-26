#include<iostream>
using namespace std;

int rad=1;

int Fibo(int n)  //피보나치 수열 함수
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

void HanoiTower(int num, char from, char by, char to)  //하노이 탑 함수
{
	if (num == 1)  //이동할 원반 1개
		cout << "원반 1을" << from << "에서" << to << "로 이동" << endl;
	else {
		//3단계 중 1단계
		HanoiTower(num - 1, from, to, by);
		//3단계 중 2단계
		cout << "원반 " << num<<"을(를)" << from<< "에서" << to << "로 이동" << endl;
		//3단계 중 3단계
		HanoiTower(num - 1, by, from, to);
	}
}

int SumCalc(int n)  //1~n까지 합(재귀함수 사용)
{
	if (n == 1) return 1;
	return n + SumCalc(n - 1);
}

int N_Reverse(int n) //입력받은 십진수를 거꾸로 출력(재귀함수 사용)
{
	if (n == 0) return 0;
	int result = N_Reverse(n / 10) + (n % 10) * rad;
	rad *= 10;
	return result;
}

int main()
{
	//피보나치 수열
	cout << "숫자 입력: ";
	int num2;
	cin >> num2;

	cout << "Fibo: ";
	for (int i = 1; i <= num2; i++)
		cout << Fibo(i) << " ";
	cout << endl<<endl;

	//하노이 탑
	cout << "하노이 탑" << endl;
	HanoiTower(3, 'A', 'B', 'C');
	cout << endl << endl;

	//1~n합
	cout << "숫자 입력: ";
	int a;
	cin >> a;
	cout<<"1~"<<a<<"까지의 합: "<<SumCalc(a) << endl<<endl;

	//입력받은 십진수를 거꾸로 출력
	cout << "숫자 입력: ";
	int b;
	cin >> b;
	cout <<b<<"를 거꾸로 출력--> " <<N_Reverse(b) << endl;
}