#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string field[12];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visit[12][6];
vector<pair<int, int>> p;

void dfs(int x, int y, char c)
{
	if (x < 0 || x >= 6 || y < 0 || y >= 12)
		return;
	else if (visit[y][x])
		return;
	else if (c != field[y][x])
		return;
	visit[y][x] = true;
	p.push_back({y, x});
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny, c);
	}
	return;
}

void fillVisit()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (field[i][j] == '.')
				visit[i][j] = true;
			else
				visit[i][j] = false;
		}
	}
}

int movePuyo()
{
	int ret = 0;

	for (int i = 0; i < 6; i++)
	{
		int eIdx = -1;
		for (int j = 11; j >= 0; j--)
		{
			if (field[j][i] == '.')
			{
				if (eIdx == -1)
					eIdx = j;
			}
			else
			{
				if (eIdx != -1)
				{
					ret = 1;
					for (int k = j; k >= 0; k--)
					{
						field[eIdx][i] = field[k][i];
						field[k][i] = '.';
						eIdx--;
					}
					eIdx = -1;
					j = 11;
				}
			}
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 12; i++)
		cin >> field[i];
	int answer = 0;
	do
	{
		fillVisit();
		bool flag = false;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				dfs(j, i, field[i][j]);
				if (p.size() >= 4)
				{
					for (int k = 0; k < p.size(); k++)
						field[p[k].first][p[k].second] = '.';
					flag = true;
				}
				p.clear();
			}
		}
		if (flag)
			answer++;
	} while (movePuyo());
	cout << answer << '\n';
	return 0;
}