#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int L, R, C;
char arr[31][31][31];
bool visit[31][31][31];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> C >> R >> L)
	{
		if (C == 0 && R == 0 && L == 0)
			break;
		queue<tuple<int, int, int>> q;
		for (int i = 0; i < C; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < L; k++)
				{
					visit[i][j][k] = false;
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S')
					{
						q.push({i, j, k});
						visit[i][j][k] = true;
					}
				}
			}
		}
		int answer = 0;
		bool flag = false;
		while (!q.empty())
		{
			int len = q.size();
			for (int i = 0; i < len; i++)
			{
				auto t = q.front(); q.pop();

				if (arr[get<0>(t)][get<1>(t)][get<2>(t)] == 'E')
				{
					flag = true;
					break;
				}
				for (int j = 0; j < 6; j++)
				{
					int nx = get<2>(t) + dx[j];
					int ny = get<1>(t) + dy[j];
					int nz = get<0>(t) + dz[j];

					if (nz >= 0 && nz < C && ny >= 0 && ny < R && nx >= 0 && nx < L)
					{
						if (arr[nz][ny][nx] != '#' && !visit[nz][ny][nx])
						{
							visit[nz][ny][nx] = true;
							q.push({nz, ny, nx});
						}
					}
				}
			}
			if (flag)
				break;
			answer++;
		}
		if (flag)
			cout << "Escaped in " << answer << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
	return 0;
}