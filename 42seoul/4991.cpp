#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int W, H;
pair<int, int> R;
char A[21][21];
bool visit[21][21];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int answer;
bool vComb[11];

void bfs(vector<int> &v, int x, int y)
{
	queue<tuple<int, int, int>> q;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			visit[i][j] = false;
	visit[y][x] = true;
	q.push({y, x, 0});
	while (!q.empty())
	{
		auto [cY, cX, cnt] = q.front(); q.pop();
		if (A[cY][cX] < 10)
			v[A[cY][cX]] = cnt;
		for (int i = 0; i < 4; i++)
		{
			int nx = cX + dx[i];
			int ny = cY + dy[i];
			if (0 <= nx && nx < W && 0 <= ny && ny < H)
			{
				if (A[ny][nx] != 'x' && !visit[ny][nx])
				{
					visit[ny][nx] = true;
					q.push({ny, nx, cnt + 1});
				}
			}
		}
	}
}

void comb(vector<vector<int>> &c, int idx, int val, int d)
{
	if (d >= c.size() - 1)
	{
		answer = min(answer, val);
		return;
	}

	for (int i = 0; i < c[idx + 1].size(); i++)
	{
		if (!vComb[i] && c[idx + 1][i] != 0)
		{
			vComb[i] = true;
			comb(c, i, val + c[idx + 1][i], d + 1);
			vComb[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> W >> H)
	{
		if (W == 0 && H == 0)
			break;
		vector<pair<int, int>> dust;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> A[i][j];
				if (A[i][j] == 'o')
					R = {i, j};
				if (A[i][j] == '*')
				{
					A[i][j] = dust.size();
					dust.push_back({i, j});
				}
			}
		}
		vector<vector<int>> C(dust.size() + 1, vector<int>(dust.size(), 0));
		bfs(C[0], R.second, R.first);
		for (int i = 1; i < C.size(); i++)
			bfs(C[i], dust[i - 1].second, dust[i - 1].first);
		answer = 1e9;
		for (int i = 0; i < C[0].size(); i++)
		{
			vComb[i] = true;
			comb(C, i, C[0][i], 1);
			vComb[i] = false;
		}
		cout << (answer == 1e9 || answer == 0 ? -1 : answer) << '\n';
	}
	return 0;
}