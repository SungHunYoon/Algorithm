#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M, K, X, A, B;
vector<int> V[300001];
bool visit[300001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		V[A].push_back(B);
	}
	set<int> answer;
	queue<int> q;
	visit[X] = true;
	for (int i = 0; i < V[X].size(); i++)
	{
		visit[V[X][i]] = true;
		q.push(V[X][i]);
	}
	int cnt = 1;
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			int t = q.front(); q.pop();
			if (cnt == K)
				answer.insert(t);
			for (int j = 0; j < V[t].size(); j++)
			{
				if (!visit[V[t][j]])
				{
					visit[V[t][j]] = true;
					q.push(V[t][j]);
				}
			}
		}
		cnt++;
	}
	if (answer.size() == 0)
		cout << "-1\n";
	else
	{
		for (auto &s : answer)
			cout << s << '\n';
	}
	return 0;
}