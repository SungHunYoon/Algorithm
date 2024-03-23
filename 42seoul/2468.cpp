#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[101][101];
bool visit[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1};
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (arr[j][k] <= i)
					visit[j][k] = true;
				else
					visit[j][k] = false;
			}
		}
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (visit[j][k])
					continue;
				queue<pair<int, int> > q;
				q.push({j, k});
				visit[j][k] = true;
				cnt++;
				while (!q.empty())
				{
					for (int l = 0; l < q.size(); l++)
					{
						auto p = q.front();
						q.pop();
						for (int m = 0; m < 4; m++)
						{
							int nx = p.second + dx[m];
							int ny = p.first + dy[m];
							if (ny >= 0 && ny < N && nx >= 0 && nx < N && !visit[ny][nx])
							{
								visit[ny][nx] = true;
								q.push({ny, nx});
							}
						}
					}
				}
			}
		}
		//cout << cnt << '\n';
		answer = max(answer, cnt);
	}
	cout << answer << '\n';
	return 0;
}