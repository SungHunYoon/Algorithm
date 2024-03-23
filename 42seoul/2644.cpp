#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, S, E, M;
vector<int> arr[101];
vector<bool> visit[101];
queue<int> q;
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> S >> E >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		visit[s].push_back(false);
		arr[e].push_back(s);
		visit[e].push_back(false);
	}
	q.push(S);
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			int c = q.front();
			q.pop();
			if (c == E)
			{
				cout << answer << '\n';
				return 0;
			}
			for (int j = 0; j < visit[c].size(); j++)
			{
				if (!visit[c][j])
				{
					visit[c][j] = true;
					q.push(arr[c][j]);
				}
			}
		}
		answer++;
	}
	cout << "-1\n";
	return 0;
}