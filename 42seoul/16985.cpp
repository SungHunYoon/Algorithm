#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int A[5][5][5];
int arr[5][5][5];
int answer = 1e9;
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};
bool vComb[5];

void rotateArray(int idx)
{
	int tmp[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			tmp[i][j] = arr[idx][5 - j - 1][i];
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			arr[idx][i][j] = tmp[i][j];
}

int bfs(int idx)
{
	int sX, sY, sZ, eX, eY, eZ;
	if (idx == 0)
	{
		sX = 0; sY = 0; sZ = 0;
		eX = 0; eY = 0; eZ = 0;
	}
	else if (idx == 1)
	{
		sX = 4; sY = 0; sZ = 0;
		eX = 0; eY = 4; eZ = 4;
	}
	else if (idx == 2)
	{
		sX = 0; sY = 4; sZ = 0;
		eX = 4; eY = 0; eZ = 4;
	}
	else
	{
		sX = 4; sY = 4; sZ = 0;
		eX = 0; eY = 0; eZ = 4;
	}
	if (!(arr[sZ][sY][sX] == 1 && arr[eZ][eY][eX] == 1))
		return 0;
	queue<tuple<int, int, int>> q;
	bool visit[5][5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				visit[i][j][k] = false;
	q.push({sZ, sY, sX});
	visit[sZ][sY][sX] = true;
	int cnt = 0;
	while (!q.empty())
	{
		int len = q.size();
		for (int j = 0; j < len; j++)
		{
			auto [z, y, x] = q.front(); q.pop();
			if (z == eZ && y == eY && x == eX)
				return cnt;
			for (int i = 0; i < 6; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && 0 <= nz && nz < 5)
				{
					if (arr[nz][ny][nx] == 1 && !visit[nz][ny][nx])
					{
						visit[nz][ny][nx] = true;
						q.push({nz, ny, nx});
					}
				}
			}
		}
		cnt++;
	}
	return 0;
}

void dfs(int idx)
{
	if (idx == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			int cnt = bfs(i);
			if (cnt != 0)
				answer = min(answer, cnt);
		}
		return;
	}

	for (int j = 0; j < 4; j++)
	{
		dfs(idx + 1);
		rotateArray(idx);
	}
}

void comb(vector<int> &v, int idx)
{
	if (idx == 5)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)
					arr[i][j][k] = A[v[i]][j][k];
		dfs(0);
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		if (!vComb[i])
		{
			vComb[i] = true;
			vector<int> t = v;
			t.push_back(i);
			comb(t, idx + 1);
			vComb[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> A[i][j][k];
	vector<int> v;
	comb(v, 0);
	if (answer == 1e9)
		cout << "-1\n";
	else
		cout << answer << '\n';
	return 0;
}