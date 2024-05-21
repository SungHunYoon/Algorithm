#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, D, C, A, B, S;
int dis[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--)
	{
		cin >> N >> D >> C;
		vector<pair<int, int>> V[10001];
		for (int i = 0; i < D; i++)
		{
			cin >> A >> B >> S;
			V[B].push_back({S, A});
		}
		fill(dis, dis + N + 1, 1e9);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dis[C] = 0;
		pq.push({0, C});
		while (!pq.empty())
		{
			auto t = pq.top(); pq.pop();
			if (dis[t.second] < t.first)
				continue;
			for (int i = 0; i < V[t.second].size(); i++)
			{
				int nV = V[t.second][i].second;
				int nDis = t.first + V[t.second][i].first;
				if (nDis < dis[nV])
				{
					dis[nV] = nDis;
					pq.push({nDis, nV});
				}
			}
		}
		int cnt = 0;
		int maxT = 0;
		for (int i = 1; i <= N; i++)
		{
			if (dis[i] != 1e9)
			{
				cnt++;
				maxT = max(maxT, dis[i]);
			}
		}
		cout << cnt << ' ' << maxT << '\n';
	}

	return 0;
}