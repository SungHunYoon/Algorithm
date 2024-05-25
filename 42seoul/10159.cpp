#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> C[101], P[101];
bool visit[101];

void child_dfs(int idx)
{
	for (int i = 0; i < C[idx].size(); i++)
	{
		if (!visit[C[idx][i]])
		{
			visit[C[idx][i]] = true;
			child_dfs(C[idx][i]);
		}
	}
}

void parent_dfs(int idx)
{
	for (int i = 0; i < P[idx].size(); i++)
	{
		if (!visit[P[idx][i]])
		{
			visit[P[idx][i]] = true;
			parent_dfs(P[idx][i]);
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
		C[a].push_back(b);
		P[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		fill(visit, visit + N + 1, false);
		visit[i] = true;
		child_dfs(i);
		parent_dfs(i);
		cout << count(visit + 1, visit + N + 1, false) << '\n';
	}
	return 0;
}
