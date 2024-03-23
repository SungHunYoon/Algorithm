#include <iostream>
#include <algorithm>

using namespace std;

int arr[6][6];
bool visit[6][6];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0,  0, 1, -1};

int cube[6];
bool cube_visit[6];
int answer[6];

int left_rotate()
{
	swap(cube[0], cube[5]);
	swap(cube[0], cube[2]);
	swap(cube[0], cube[4]);
	for (int i = 0; i < 6; i++)
		cout << cube[i] << ' ';
	cout << '\n';
}

int right_rotate()
{
	swap(cube[0], cube[4]);
	swap(cube[0], cube[2]);
	swap(cube[0], cube[5]);
	for (int i = 0; i < 6; i++)
		cout << cube[i] << ' ';
	cout << '\n';
}

int up_rotate()
{
	swap(cube[0], cube[3]);
	swap(cube[3], cube[2]);
	swap(cube[2], cube[1]);
	for (int i = 0; i < 6; i++)
		cout << cube[i] << ' ';
	cout << '\n';
}

int down_rotate()
{
	swap(cube[0], cube[1]);
	swap(cube[1], cube[2]);
	swap(cube[2], cube[3]);
	for (int i = 0; i < 6; i++)
		cout << cube[i] << ' ';
	cout << '\n';
}

void dfs(int x, int y)
{
	if (x < 0 || x > 5 || y < 0 || y > 5 || arr[y][x] == 0 || visit[y][x])
		return;
	if (cube_visit[arr[y][x]] != -1)
		return;
	visit[y][x] = true;
	cube_visit[arr[y][x]] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		dfs(ny, nx);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	pair<int, int> p;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				p = {i, j};
				visit[i][j] = true;
				cube_visit[0] = true;
			}
		}
	}
	for (int i = 0; i < 6; i++)
		cube[i] = i;
	return 0;
}