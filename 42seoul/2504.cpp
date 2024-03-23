#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> stk;
int answer;
int accum = 1;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			stk.push(str[i]);
			accum *= 2;
		}
		else if (str[i] == '[')
		{
			stk.push(str[i]);
			accum *= 3;
		}
		else if (str[i] == ')')
		{
			if (stk.empty() || stk.top() != '(')
			{
				answer = 0;
				break;
			}
			stk.pop();
			if (str[i - 1] == '(')
				answer += accum;
			accum /= 2;
		}
		else
		{
			if (stk.empty() || stk.top() != '[')
			{
				answer = 0;
				break;
			}
			stk.pop();
			if (str[i - 1] == '[')
				answer += accum;
			accum /= 3;
		}
	}
	if (!stk.empty())
		answer = 0;
	cout << answer << '\n';
	return 0;
}