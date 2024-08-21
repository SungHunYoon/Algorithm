#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, A, B, D;
vector<pair<int, int>> V[1001];
bool visit[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B >> D;
		V[A].push_back({B, D});
		V[B].push_back({A, D});
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		queue<pair<int, int>> q;
		fill(visit + 1, visit + N + 1, false);
		for (int j = 0; j < V[A].size(); j++)
		{
			visit[V[A][j].first] = true;
			q.push({V[A][j]});
		}
		while (!q.empty())
		{
			auto t = q.front(); q.pop();
			if (t.first == B)
			{
				cout << t.second << '\n';
				break;
			}
			for (int j = 0; j < V[t.first].size(); j++)
			{
				if (visit[V[t.first][j].first]) continue;
				visit[V[t.first][j].first] = true;
				q.push({V[t.first][j].first, t.second + V[t.first][j].second});
			}
		}
	}
	return 0;
}