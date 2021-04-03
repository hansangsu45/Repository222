#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	//queue
	queue<pair<int, string>> q;

	q.push(make_pair(10,"½Ê"));

	pair<int, string> t = make_pair(3, "»ï");
	q.push(t);

	int i = 7; string s = "Ä¥";
	q.push(make_pair(i, s));
	
	cout << q.size() << endl;
	cout << q.front().first << " " << q.front().second<<endl;
	cout << q.back().first << " " << q.back().second << endl;

	while (!q.empty())
	{
		pair<int, string> n = q.front();
		q.pop();

		cout << n.first << ' ' << n.second << "\n";
	}

	cout << q.size()<<endl;

	q.push(make_pair(4, "»ç"));
	q.push(make_pair(5, "¿À"));


	queue<pair<int, string>> emt;
	swap(q, emt);

	cout << q.size()<<" "<<emt.size()<<endl<<endl;



	//stack
	stack<double> sd;

	sd.push(3.14);
	sd.push(2.732);
	sd.push(1.414);
	sd.push(2.236);
	sd.push(2.718);

	cout << sd.size() << endl;
	
	while (!sd.empty())
	{
		double d=sd.top();
		sd.pop();

		cout << d << '\n';
	}

	cout << sd.size() << endl;
}