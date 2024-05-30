#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, A, B, C, X, Y;
vector<pair<int, int>> V[100001];
bool visit[100001];

int bfs(int weight)
{
	fill(visit, visit + N + 1, false);
	queue<int> q;
	visit[X] = true;
	q.push(X);
	while (!q.empty())
	{
		int t = q.front(); q.pop();
		if (t == Y)
			return 1;
		for (int i = 0; i < V[t].size(); i++)
		{
			if (!visit[V[t][i].first] && V[t][i].second >= weight)
			{
				visit[V[t][i].first] = true;
				q.push(V[t][i].first);
			}
		}
	}
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		V[A].push_back({B, C});
		V[B].push_back({A, C});
	}
	cin >> X >> Y;

	int start = 0, end = 1e9, mid;
	int answer = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (bfs(mid))
		{
			answer = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << answer << '\n';
	return 0;
}