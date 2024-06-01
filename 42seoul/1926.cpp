#include <iostream>
#include <queue>

using namespace std;

int N, M;
int A[501][501];
bool visit[501][501];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	int cnt = 0;
	visit[y][x] = true;
	q.push({x, y});
	while (!q.empty())
	{
		auto t = q.front(); q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N)
			{
				if (A[ny][nx] == 1 && !visit[ny][nx])
				{
					visit[ny][nx] = true;
					q.push({nx, ny});
				}
			}
		}
	}
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	int cnt = 0;
	int maxArea = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] == 1 && !visit[i][j])
			{
				maxArea = max(maxArea, bfs(j, i));
				cnt++;
			}
		}
	}
	cout << cnt << '\n' << maxArea << '\n';
	return 0;
}