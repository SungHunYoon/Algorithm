#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, C, M;
vector<int> V[10001];
queue<pair<int, int>> q;
int T[10001];
int D[10001];
int MT[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> C;
		for (int j = 0; j < C; j++)
		{
			cin >> M;
			V[M].push_back(i);
			D[i]++;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (D[i] == 0)
			q.push({i, T[i]});
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		int len = q.size();
		while (len--)
		{
			auto t = q.front(); q.pop();
			answer = max(answer, t.second);
			for (int j = 0; j < V[t.first].size(); j++)
			{
				int p = V[t.first][j];
				MT[p] = max(MT[p], t.second + T[p]);
				if (--D[p] == 0)
					q.push({p, MT[p]});
			}
		}
	}
	cout << answer << '\n';
	return 0;
}