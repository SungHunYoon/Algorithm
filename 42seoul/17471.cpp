#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, G;
int A[11];
vector<int> V[11];
bool visit[11];
int answer = 1e9;

int bfs(vector<int> &v)
{
	int ret = 0;
	int cnt = 0;
	queue<int> q;
	visit[v[0]] = true;
	q.push(v[0]);
	while (!q.empty())
	{
		int t = q.front(); q.pop();

		ret += A[t];
		cnt++;
		
		for (int i = 0; i < V[t].size(); i++)
		{
			if (!visit[V[t][i]])
			{
				for (int j = 0; j < v.size(); j++)
				{
					if (v[j] == V[t][i])
					{
						visit[V[t][i]] = true;
						q.push(V[t][i]);
						break;
					}
				}
			}
		}
	}
	if (v.size() != cnt)
		ret = -1;
	return ret;
}

void comb(vector<int> c, int cnt, int idx)
{
	if (idx > N)
		return;
	if (cnt == c.size())
	{
		fill(visit, visit + 1 + N, false);
		int a = bfs(c);
		if (a == -1)
			return;
		vector<int> t;
		for (int i = 1; i <= N; i++)
		{
			int j;
			for (j = 0; j < c.size(); j++)
			{
				if (c[j] == i)
					break;
			}
			if (j >= c.size())
				t.push_back(i);
		}
		int b = bfs(t);
		if (b == -1)
			return;
		answer = min(answer, abs(a - b));
		return;
	}

	comb(c, cnt, idx + 1);
	vector<int> t = c;
	t.push_back(idx + 1);
	comb(t, cnt, idx + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i <= N; i++)
	{
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> G;
			V[i].push_back(G);
		}
	}
	for (int i = 1; i <= N / 2; i++)
	{
		vector<int> c;
		comb(c, i, 0);
	}
	if (answer == 1e9)
		answer = -1;
	cout << answer << '\n';
	return 0;
}