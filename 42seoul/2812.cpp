#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N, K;
string str;
stack<char> stk;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K >> str;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (stk.empty())
			stk.push(str[i]);
		else
		{
			while (cnt < K && !stk.empty() && stk.top() < str[i])
			{
				stk.pop();
				cnt++;
			}
			stk.push(str[i]);
		}
	}
	string answer;
	while (!stk.empty())
	{
		answer.append(1, stk.top());
		stk.pop();
	}
	if (answer.size() > N - K)
		answer = answer.substr(answer.size() - (N - K));
	for (auto it = answer.rbegin(); it != answer.rend(); it++)
		cout << *it;
	cout << '\n';
	return 0;
}

