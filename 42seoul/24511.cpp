#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

int N, M;
vector<int> ds(100001);
stack<int> stk;
deque<int> dq;
vector<int> answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> ds[i];
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (ds[i] == 0)
			dq.push_back(tmp);
		else
			stk.push(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		if (!dq.empty())
		{
			answer.push_back(dq.back());
			dq.pop_back();
			dq.push_front(tmp);
		}
		else
			answer.push_back(tmp);
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	cout << '\n';
	return 0;
}