#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;
string str;
int table[26];
int answer;
stack<double> stk;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> str;

	for (int i = 0; i < N; i++)
		cin >> table[i];
	
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/')
		{
			double a = stk.top();
			stk.pop();
			double b = stk.top();
			stk.pop();

			if (str[i] == '*')
				stk.push(b * a);
			else if (str[i] == '+')
				stk.push(b + a);
			else if (str[i] == '-')
				stk.push(b - a);
			else
				stk.push(b / a);
		}
		else
			stk.push(table[str[i] - 'A']);
	}
	cout << fixed;
	cout.precision(2);
	cout << stk.top() << endl;
	return 0;
}