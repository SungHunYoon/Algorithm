#include <iostream>
#include <algorithm>

using namespace std;

int arr[6][6];
int visit[6][6];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int cube[6];
bool cube_visit[6];
int cnt;

void left()
{
	swap(cube[0], cube[5]);
	swap(cube[0], cube[2]);
	swap(cube[0], cube[4]);
}

void right()
{
	swap(cube[0], cube[4]);
	swap(cube[0], cube[2]);
	swap(cube[0], cube[5]);
}

void up()
{
	swap(cube[0], cube[3]);
	swap(cube[3], cube[2]);
	swap(cube[2], cube[1]);
}

void down()
{
	swap(cube[0], cube[1]);
	swap(cube[1], cube[2]);
	swap(cube[2], cube[3]);
}

void dfs(int x, int y)
{
	if (x < 0 || x > 5 || y < 0 || y > 5 || arr[y][x] == 0 || visit[y][x])
		return;
	if (cube_visit[cube[0]])
		return;
	visit[y][x] = true;
	cube_visit[cube[0]] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		int cp[6];
		copy(cube, cube + 6, cp);
		if (i == 0)
			right();
		else if (i == 1)
			left();
		else if (i == 2)
			down();
		else
			up();
		dfs(nx, ny);
		copy(cp, cp + 6, cube);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 3; i++)
	{
		bool flag = false;
		pair<int, int> p;
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				cin >> arr[j][k];
				if (arr[j][k] == 1)
				{
					if (!flag)
					{
						p = {j, k};
						flag = true;
					}
				}
				visit[j][k] = false;
			}
		}
		for (int j = 0; j < 6; j++)
		{
			cube[j] = j;
			cube_visit[j] = false;
		}
		dfs(p.second, p.first);
		flag = false;
		for (int j = 0; j < 6; j++)
		{
			if (!cube_visit[j])
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "no\n";
		else
			cout << "yes\n";
	}

	return 0;
}