#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B;
vector<int> V[501];
queue<int> q;
bool visit[501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	int idx = 0;
	int answer = 0;
	q.push(1);
	visit[1] = true;
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			int t = q.front(); q.pop();
			answer++;
			for (int j = 0; j < V[t].size(); j++)
			{
				if (!visit[V[t][j]])
				{
					visit[V[t][j]] = true;
					q.push(V[t][j]);
				}
			}
		}
		idx++;
		if (idx > 2)
			break;
	}
	cout << answer - 1 << '\n';
	return 0;
}