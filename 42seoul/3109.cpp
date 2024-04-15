#include <iostream>

using namespace std;

int R, C;
bool arr[10001][501];
int dy[3] = {-1, 0, 1};
int answer;

int dfs(int x, int y)
{
	int ret = 0;

	if (x == C - 1)
	{
		// cout << x << " " << y << '\n';
		answer++;
		return 1;
	}
	for (int i = 0; i < 3; i++)
	{
		int nx = x + 1;
		int ny = y + dy[i];

		if (ny >= 0 && ny < R && !arr[ny][nx])
		{
			arr[ny][nx] = true;
			if ((ret = dfs(nx, ny)) == 1)
				break;
			//arr[ny][nx] = false;
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char tmp;
			cin >> tmp;
			if (tmp == 'x')
				arr[i][j] = true;
		}
	}
	for (int i = 0; i < R; i++)
		dfs(0, i);
	cout << answer << '\n';
	return 0;
}
