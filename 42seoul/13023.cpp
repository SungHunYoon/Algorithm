#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> V[2001];
bool visit[2001];

int dfs(vector<int> &v, int cnt)
{
	if (cnt >= 4)
		return 1;

	for (int i = 0; i < v.size(); i++)
	{
		if (!visit[v[i]])
		{
			visit[v[i]] = true;
			if (dfs(V[v[i]], cnt + 1) > 0)
				return 1;
			visit[v[i]] = false;
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
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		visit[i] = true;
		if (dfs(V[i], 0) > 0)
		{
			cout << "1\n";
			return 0;
		}
		visit[i] = false;
	}
	cout << "0\n";
	return 0;
}