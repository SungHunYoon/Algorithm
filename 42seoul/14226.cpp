#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int S;
bool visit[1001][1001];
queue<pair<pair<int, int>, int>> q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	q.push({{1, 0}, 0});
	visit[1][0] = true;
	while (!q.empty())
	{
		auto t = q.front(); q.pop();
		if (t.first.first == S)
		{
			cout << t.second << '\n';
			return 0;
		}
		if (t.first.first + t.first.second <= 1000 &&
			!visit[t.first.first + t.first.second][t.first.second])
		{
			visit[t.first.first + t.first.second][t.first.second] = true;
			q.push({{t.first.first + t.first.second, t.first.second}, t.second + 1});
		}
		if (t.first.first <= 1000 && !visit[t.first.first][t.first.first])
		{
			visit[t.first.first][t.first.first] = true;
			q.push({{t.first.first, t.first.first}, t.second + 1});
		}
		if (t.first.first - 1 >= 0 && !visit[t.first.first - 1][t.first.second])
		{
			visit[t.first.first - 1][t.first.second] = true;
			q.push({{t.first.first - 1, t.first.second}, t.second + 1});
		}
	}
	return 0;
}