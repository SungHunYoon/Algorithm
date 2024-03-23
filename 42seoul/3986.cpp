#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		stack<char> stk;
		for (int j = 0; j < str.length(); j++)
		{
			if (stk.empty() || stk.top() != str[j])
				stk.push(str[j]);
			else
				stk.pop();
		}
		if (stk.empty())
			answer += 1;
	}
	cout << answer << '\n';
	return 0;
}