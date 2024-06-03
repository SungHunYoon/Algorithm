#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, R, C;
int A[101][101];
bool visit[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int r, int c)
{
	queue<pair<int, int>> q;
	int cnt = 0;
	visit[r][c] = true;
	q.push({r, c});
	while (!q.empty())
	{
		auto t = q.front(); q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nx = t.second + dx[i];
			int ny = t.first + dy[i];
			
			if (1 <= nx && nx <= M && 1 <= ny && ny <= N && A[ny][nx] == 1 && !visit[ny][nx])
			{
				visit[ny][nx] = true;
				q.push({ny, nx});
			}
		}
	}
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> R >> C;
		A[R][C] = 1;
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (A[i][j] == 1 && !visit[i][j])
				answer = max(answer, bfs(i, j));
		}
	}
	cout << answer << '\n';
	return 0;
}