#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int K, V, E;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;
		int visit[V + 1];
		vector<int> v[V + 1];
		fill(visit, visit + V + 1, 0);
		for (int j = 0; j < E; j++)
		{
			int start, end;
			cin >> start >> end;
			v[start].push_back(end);
			v[end].push_back(start);
		}
		bool flag = true;
		for (int j = 1; j <= V; j++)
		{
			queue<pair<int, int>> q;
			if (visit[j] != 0)
				continue;
			q.push({j, 0});
			visit[j] = 1;
			while (!q.empty())
			{
				int len = q.size();
				for (int l = 0; l < len; l++)
				{
					auto t = q.front(); q.pop();
					for (int k = 0; k < v[t.first].size(); k++)
					{
						if (visit[v[t.first][k]] == 0)
						{
							q.push({v[t.first][k], t.second + 1});
							visit[v[t.first][k]] = (t.second + 1) % 2 == 0 ? 1 : 2;
						}
						if (visit[t.first] == visit[v[t.first][k]])
						{
							flag = false;
							break;
						}
					}
					if (!flag)
						break;
				}
				if (!flag)
					break;
			}
			if (!flag)
				break;
		}
		// for (int k = 1; k <= V; k++)
		// 	cout << visit[k] << '\n';
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}