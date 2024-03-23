#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int T, L;
pair<int, int> s;
pair<int, int> e;
bool visit[301][301];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> L;
		cin >> s.first >> s.second;
		cin >> e.first >> e.second;
		queue<pair<int, int> > q;
		for (int j = 0; j < L; j++)
			for (int k = 0; k < L; k++)
				visit[j][k] = false;
		q.push(s);
		visit[s.first][s.second] = true;
		bool flag = false;
		answer = 0;
		while (!q.empty())
		{
			int len = q.size();
			for (int j = 0; j < len; j++)
			{
				auto p = q.front();
				q.pop();

				if (p == e)
				{
					flag = true;
					break;
				}
				for (int k = 0; k < 8; k++)
				{
					int nx = p.second + dx[k];
					int ny = p.first + dy[k];

					if (ny >= 0 && ny < L && nx >= 0 && nx < L && !visit[ny][nx])
					{
						visit[ny][nx] = true;
						q.push({ny, nx});
					}
				}
			}
			if (flag)
				break;
			answer++;
		}
		cout << answer << '\n';
	}

	return 0;
}