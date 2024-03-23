#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;
stack<int> stk;
long long answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (stk.empty())
			stk.push(tmp);
		else
		{
			while (!stk.empty())
			{
				if (stk.top() <= tmp)
					stk.pop();
				else
					break;
			}
			answer += stk.size();
			stk.push(tmp);
		}
	}
	cout << answer << '\n';
	return 0;
}