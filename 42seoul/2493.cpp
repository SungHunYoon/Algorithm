#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;
stack<pair<int, int> > stk;
vector<int> answer;

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
		bool flag = false;
		while (!stk.empty())
		{
			if (stk.top().first > tmp)
			{
				answer.push_back(stk.top().second + 1);
				flag = true;
				break;
			}
			stk.pop();
		}
		if (!flag)
			answer.push_back(0);
		stk.push(make_pair(tmp, i));
	}

	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";
	cout << '\n';

	return 0;
}