#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
bool visit[101][101];
vector<int> answer;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		pair<int, int> s, e;

		cin >> s.first >> s.second;
		cin >> e.first >> e.second;
		for (int j = s.first; j < e.first; j++)
			for (int k = M - e.second; k < M - s.second; k++)
				visit[k][j] = true;
	}
	// for (int i = 0; i < M; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 		cout << visit[i][j] << ' ';
	// 	cout << '\n';
	// }
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j])
				continue;
			queue<pair<int, int> > q;
			q.push({i, j});
			visit[i][j] = true;
			int cnt = 0;
			while (!q.empty())
			{
				int len = q.size();
				for (int k = 0; k < len; k++)
				{
					auto p = q.front();
					q.pop();
					cnt++;
					// cout << p.first << " " << p.second << '\n';	
					for (int l = 0; l < 4; l++)
					{
						int nx = p.second + dx[l];
						int ny = p.first + dy[l];
						
						if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visit[ny][nx])
						{
							visit[ny][nx] = true;
							q.push({ny, nx});
						}
					}
				}
			}
			answer.push_back(cnt);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	cout << '\n';
	return 0;
}