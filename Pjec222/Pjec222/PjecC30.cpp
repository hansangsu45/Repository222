#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;

int main()
{
		stack<int> si;
	stack<int> si2;

	string s_input;
	cout << "마지막에 '='기호 붙여야 함." << endl;
	cin >> s_input;

	int count = 1;
	int sum[10] = { 0, };
	int index = 0;
	int ce = 0;
	string s = "";

#pragma region 괄호 변수
	int count2 = 1;
	int sum2[10] = { 0, };
	int index2 = 0;
	int ce2;
	string sss = "";
	vector<int> inCalc;
	bool isLast = false, isIn=false;
	queue<int> qu;
	pair<int, int> che = make_pair(-1, -1);
	
#pragma endregion

#pragma region 괄호 안의 계산

	for (int i = 0; i < s_input.size(); i++)
	{
		isLast = false;
		if (s_input[i] == '(')
		{
			isIn = true;
			che.first = i;
			ce2 = i + 1;
			for (int j = ce2; !isLast; j++)
			{
				if (s_input[j] == '+' || s_input[j] == '-' || s_input[j] == '*' || s_input[j] == '/' || s_input[j] == ')')
				{
					if (s_input[j] == '+')  sss += '+';
					else if (s_input[j] == '-') sss += '-';
					else if (s_input[j] == '*') sss += '*';
					else if (s_input[j] == '/') sss += '/';
					else if (s_input[j] == ')') { sss += ')';  isLast = true; che.second = j-1; }

					for (int k = j - 1; k >= ce2; k--)
					{
						sum2[index2] += (s_input[k] - '0') * count2;
						count2 *= 10;
					}

					if (sss.size() >= 2)
					{
						if (sss[sss.size() - 2] == '*')
						{
							sum2[index2] = sum2[index2] * sum2[index2 - 1];
							
							inCalc[inCalc.size() - 1] = sum2[index2];   
							goto ONE;
						}
						else if (sss[sss.size() - 2] == '/')
						{
							sum2[index2] = sum2[index2 - 1] / sum2[index2];
							
							inCalc[inCalc.size() - 1] = sum2[index2];
							goto ONE;
						}
					}

					inCalc.push_back(sum2[index2]);

				ONE:

					count2 = 1;
					index2++;
					ce2 = j + 1;
				}
			}
		}
	}

	if (isIn) {
		for (int u = 0; u < inCalc.size(); u++)
		{
			qu.push(inCalc[u]);
		}

		int n5 = 0;
		for (int m = 0; m < sss.size() - 1; m++)
		{
			if (sss[m] == '*' || sss[m] == '/') continue;

			int a, b;

			a = qu.front();
			qu.pop();
			b = qu.front();
			qu.pop();

			if (sss[m] == '+')
			{
				qu.push(a + b);
			}
			else if (sss[m] == '-')
			{
				qu.push(a - b);
			}
			n5 = qu.front();
		}

		if (sss.size() == 2)
		{
			if (sss[0] == '*' || sss[0] == '/')
			{
				n5 = qu.front();
				qu.pop();
			}
		}

		string sr = to_string(n5);
		if (che.first != -1)
			s_input.replace(che.first, che.second, sr);

		//cout << endl << "n5: " << n5 << "   " << "replace: " << s_input << endl;
	}
#pragma endregion

	for (int i = 0; i < s_input.size(); i++)
	{
		if (s_input[i] == '+' || s_input[i] == '-' || s_input[i] == '*' || s_input[i] == '/' || s_input[i]=='=')
		{
			if (s_input[i] == '+')  s+= '+';
			else if (s_input[i] == '-') s+= '-';
			else if (s_input[i] == '*') s+= '*';
			else if (s_input[i] == '/') s+= '/';
			else if(s_input[i] == '=') s += '=';

			for (int j = i-1; j >=ce; j--)
			{
				sum[index] += (s_input[j] - '0') * count;
				count*=10;
			}

			if (s.size() >= 2) 
			{
				if (s[s.size() - 2] == '*')
				{
					sum[index] = sum[index] * sum[index - 1];
					si.pop();
				}
				else if (s[s.size() - 2] == '/')
				{
					sum[index] = sum[index - 1] / sum[index];
					si.pop();
				}
			}

			si.push(sum[index]);
			count = 1;
			index++;
			ce = i+1;
		}
	}
	
	while (!si.empty())
	{
		si2.push(si.top());
		si.pop();
	}

	for (int i = 0; i < s.size()-1; i++)
	{
		if (s[i] != '*' && s[i] != '/') 
		{
			int a, b;

			if (si.empty()) {
				a = si2.top();
				si2.pop();
				b = si2.top();
				si2.pop();
			}
			else {
				a = si.top();
				si.pop();
				b = si2.top();
				si2.pop();
			}

			if (s[i] == '+')
			{
				si.push(a + b);
			}
			else if (s[i] == '-')
			{
				si.push(a - b);
			}
		}
	}

	int n4 = 0;
	if (s.size() == 2)
	{
		if (s[0] == '*' || s[0] == '/')
		{
			n4 = si2.top();
			si2.pop();
		}
	}

	while (!si.empty())
	{
		n4 += si.top();
		si.pop();
	}
	cout << n4 << endl << endl;
}