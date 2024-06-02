#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using LL = long long;

int N, M, A, B;
vector<int> V[10001];
bool visit[10001];

LL bfs(int idx)
{
	fill(visit, visit + N + 1, false);
	queue<int> q;
	LL cnt = 0;
	visit[idx] = true;
	q.push(idx);
	while (!q.empty())
	{
		int t = q.front(); q.pop();
		cnt++;
		for (int i = 0; i < V[t].size(); i++)
		{
			if (!visit[V[t][i]])
			{
				visit[V[t][i]] = true;
				q.push(V[t][i]);
			}
		}
	}
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		V[B].push_back(A);
	}
	vector<int> answer;
	LL maxCnt = 0;
	for (int i = 1; i <= N; i++)
	{
		LL cnt = bfs(i);
		if (maxCnt < cnt)
		{
			maxCnt = cnt;
			answer.clear();
		}
		if (maxCnt == cnt)
			answer.push_back(i);
	}
	for (int &it : answer)
		cout << it << ' ';
	cout << '\n';
	return 0;
}