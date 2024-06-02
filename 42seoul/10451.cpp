#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int T, N;
int A[1001];
int D[1001];
bool visit[1001];
stack<int> s;
vector<vector<int>> SCC;

int dfs(int idx, int cnt)
{
	D[idx] = ++cnt;
	s.push(idx);

	int parent = D[idx];
	int next = A[idx];
	if (D[next] == 0)
		parent = min(parent, dfs(next, cnt));
	else if (!visit[next])
		parent = min(parent, D[next]);
	if (parent == D[next])
	{
		vector<int> scc;
		while (!s.empty())
		{
			int t = s.top(); s.pop();
			scc.push_back(t);
			visit[t] = true;
			if (t == idx)
				break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> A[i];
		for (int i = 1; i <= N; i++)
		{
			if (D[i] == 0)
				dfs(i, 0);
		}
		cout << SCC.size() << '\n';
		SCC.clear();
		fill(visit, visit + N + 1, false);
		fill(D, D + N + 1, 0);
	}

	return 0;
}