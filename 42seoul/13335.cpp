#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, W, L;
vector<pair<int, int> > vec;
queue<pair<int, int> > q;
int weight;
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> W >> L;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		vec.push_back({tmp, 0});
	}
	q.push(vec[0]);
	weight += vec[0].first;
	answer++;
	int i = 1;
	while (!q.empty())
	{
		int len = q.size();
		for (int j = 0; j < len; j++)
		{
			auto t = q.front();
			q.pop();
			t.second++;
			//cout << t.first << " " << t.second << '\n';
			if (t.second >= W)
				weight -= t.first;
			else
				q.push(t);
		}
		if (i < N && weight + vec[i].first <= L)
		{
			q.push(vec[i]);
			weight += vec[i].first;
			i++;
		}
		answer++;
		//cout << answer << " weight : " << weight << '\n';
	}
	cout << answer << '\n';

	return 0;
}