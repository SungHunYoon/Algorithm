#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<pair<int, int> > stk;
vector<int> answer(1000001, -1);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (stk.empty())
			stk.push({num, i});
		else
		{
			auto t = stk.top();
			while (!stk.empty())
			{
				if (stk.top().first >= num)
					break;
				else
				{
					answer[stk.top().second] = num;
					stk.pop();
				}
			}
			stk.push({num, i});
		}
	}
	for (int i = 0; i < N; i++)
		cout << answer[i] << ' ';
	cout << '\n';
	return 0;
}