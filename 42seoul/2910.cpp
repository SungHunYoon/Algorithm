#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, C;
deque<pair<int, int> > dq;

bool cmp(const pair<int, int> &l, const pair<int, int> &r)
{
	return l.second > r.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		auto it = dq.begin();
		for (; it != dq.end(); it++)
		{
			if ((*it).first == tmp)
				break;
		}
		if (it == dq.end())
			dq.push_back({tmp, 1});
		else
			(*it).second++;
	}
	stable_sort(dq.begin(), dq.end(), cmp);
	for (int i = 0; i < dq.size(); i++)
	{
		for (int j = 0; j < dq[i].second; j++)
			cout << dq[i].first << ' ';
	}
	cout << '\n';

	return 0;
}