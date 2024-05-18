#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[51][51];
bool visit[251][51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<pair<int, int>, int>> q;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c; cin >> c;
			arr[i][j] = c - '0';
		}
	}
	int answer = 0;
	while (answer < N * N)
	{
		for (int i = 0; i < 251; i++)
			for (int j = 0; j < 51; j++)
				for (int k = 0; k < 51; k++)
					visit[i][j][k] = false;
		q.push({{0, 0}, 0});
		visit[0][0][0] = true;
		while (!q.empty())
		{
			auto t = q.front(); q.pop();
			if (t.first.first == N - 1 && t.first.second == N - 1)
			{
				cout << answer << '\n';
				return 0;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = t.first.second + dx[i];
				int ny = t.first.first + dy[i];
				if (0 <= nx && nx < N && 0 <= ny && ny < N)
				{
					if (arr[ny][nx] == 1 && !visit[t.second][ny][nx])
					{
						visit[t.second][ny][nx] = true;
						q.push({{ny, nx}, t.second});
					}
					if (t.second + 1 <= answer && arr[ny][nx] == 0 && !visit[t.second + 1][ny][nx])
					{
						visit[t.second + 1][ny][nx] = true;
						q.push({{ny, nx}, t.second + 1});
					}
				}
			}
		}
		answer++;
	}
	return 0;
}