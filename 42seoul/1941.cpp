#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int A[5][5];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool visit[5][5];
int answer;

bool check(vector<int> &v)
{
	int cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (A[v[i] / 5][v[i] % 5] == 0)
			cnt++;
	}
	if (cnt >= 4)
		return false;
	return true;
}

bool bfs(vector<int> &v)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			visit[i][j] = false;
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++)
	{
		if (q.empty())
			q.push({v[i] / 5, v[i] % 5});
		else
			visit[v[i] / 5][v[i] % 5] = true;
	}
	int cnt = 0;
	while (!q.empty())
	{
		auto t = q.front(); q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nx = t.second + dx[i];
			int ny = t.first + dy[i];
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && visit[ny][nx])
			{
				visit[ny][nx] = false;
				q.push({ny, nx});
			}
		}
	}
	if (cnt < 7)
		return false;
	return true;
}

void dfs(vector<int> v, int idx, int cnt)
{
	if (idx > 25)
		return;
	if (cnt >= 7)
	{
		if (!check(v))
			return;
		if (!bfs(v))
			return;
		answer++;
		return;
	}

	dfs(v, idx + 1, cnt);
	v.push_back(idx);
	dfs(v, idx + 1, cnt + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char c; cin >> c;
			if (c == 'S')
				A[i][j] = 1;
		}
	}
	vector<int> v;
	dfs(v, 0, 0);
	cout << answer << '\n';
	return 0;
}