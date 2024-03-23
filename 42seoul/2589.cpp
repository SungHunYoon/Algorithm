#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int arr[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			if (c == 'W')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				queue<pair<pair<int, int>, int> > q;
				vector<vector<bool> > visit(51, vector<bool>(51, false));
				q.push(make_pair(make_pair(i, j), 0));
				visit[i][j] = true;
				while (!q.empty())
				{
					for (size_t k = 0; k < q.size(); k++)
					{
						pair<int, int> pos = q.front().first;
						int cnt = q.front().second;
						q.pop();

						for (int l = 0; l < 4; l++)
						{
							int nx = pos.second + dx[l];
							int ny = pos.first + dy[l];
							if (0 <= nx && nx < M && 0 <= ny && ny < N)
							{
								if (arr[ny][nx] == 0 && !visit[ny][nx])
								{
									visit[ny][nx] = true;
									q.push(make_pair(make_pair(ny, nx), cnt + 1));
									answer = max(answer, cnt + 1);
								}
							}
						}
					}
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}