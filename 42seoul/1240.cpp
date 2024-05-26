#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> V[1001];
bool visit[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		V[a].push_back({b, d});
		V[b].push_back({a, d});
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		queue<pair<int, int>> q;
		fill(visit + 1, visit + N + 1, false);
		for (int j = 0; j < V[a].size(); j++)
		{
			visit[V[a][j].first] = true;
			q.push({V[a][j]});
		}
		while (!q.empty())
		{
			auto t = q.front(); q.pop();
			if (t.first == b)
			{
				cout << t.second << '\n';
				break;
			}
			for (int j = 0; j < V[t.first].size(); j++)
			{
				if (!visit[V[t.first][j].first])
				{
					visit[V[t.first][j].first] = true;
					q.push({V[t.first][j].first, t.second + V[t.first][j].second});
				}
			}
		}
	}
	return 0;
}