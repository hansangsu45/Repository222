#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int main()
{
	cout << "숫자 입력: ";
	int n3;
	cin >> n3;
	stack<char> st;
	vector<char> v;
	string str = to_string(n3);
	int k = 0;
	int m = 0;

	if (str.size() > 3)
	{
		for (int j = 0; j < str.size(); j++)
		{
			st.push(str[j]);

			k++;
			if (k % 3 == 0 && k != str.size()&&str.size()%3==0)
			{
				st.push(',');
			}
			else if (j==1+m*3 && k != str.size() && str.size() % 3 == 2)
			{
				st.push(',');
				m++;
			}
			else if (j%3==0 && k != str.size() && str.size() % 3 == 1)
			{
				st.push(',');
				m++;
			}
		}

		while (!st.empty())
		{
			v.push_back(st.top());
			st.pop();
		}

		reverse(v.begin(), v.end());

		for (auto a : v) {
			cout << a;
		}

		cout << endl;
	}
	else {
		cout << str << endl;
	}
}
