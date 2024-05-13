#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> P[501];
vector<int> V[501];
bool visit[501];

void dfs(vector<int> &v, bool flag)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (!visit[v[i]])
		{
			visit[v[i]] = true;
			if (flag == false)
				dfs(V[v[i]], flag);
			else
				dfs(P[v[i]], flag);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		V[b].push_back(a);
		P[a].push_back(b);
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		fill(visit, visit + N + 1, false);
		visit[i] = true;
		dfs(V[i], false);
		dfs(P[i], true);
		if (count(visit + 1, visit + N + 1, false) == 0)
			answer++;
	}
	cout << answer << '\n';
	return 0;
}