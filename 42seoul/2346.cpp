#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int N;
deque<pair<int, int> > dq;
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
		dq.push_back(make_pair(tmp, i));
	}

	int idx = 0;
	answer.push_back(dq[0].second);
	for (int i = 0; i < N - 1; i++)
	{
		int nextIdx = idx + dq[idx].first;
		dq.erase(dq.begin() + idx);
		if (nextIdx >= (int)dq.size())
			nextIdx = nextIdx % dq.size() - 1;
		else if (idx < nextIdx)
			nextIdx -= 1;
		while (nextIdx < 0)
			nextIdx += dq.size();
		idx = nextIdx;
		answer.push_back(dq[idx].second);
	}

	for (int i = 0; i < N; i++)
		cout << answer[i] + 1 << " ";
	cout << '\n';

	return 0;
}