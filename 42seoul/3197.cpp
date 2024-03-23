#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
int arr[1501][1501];
bool visit[1501][1501];
int parent[562501];
pair<int, int> swan[2];
int swan_pos[2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<pair<int, int>, int> > q;

int find(int index)
{
	if (parent[index] == index)
		return index;
	parent[index] = find(parent[index]);
	return parent[index];
}

void make_union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return;

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C;
	bool flag = false;
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			if (str[j] == '.')
				arr[i][j] = -2;
			else if (str[j] == 'X')
				arr[i][j] = -1;
			else if (str[j] == 'L')
			{
				if (!flag)
					swan[0] = {i, j};
				else
					swan[1] = {i, j};
				flag = true;
				arr[i][j] = -2;
			}
		}
	}

	int cnt = 0;
	vector<pair<pair<int, int>, int> > v;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == -2)
			{
				arr[i][j] = cnt + 1;
				q.push({{i, j}, cnt + 1});
				visit[i][j] = true;
				while (!q.empty())
				{
					auto p = q.front();
					q.pop();

					if (swan[0].first == p.first.first && swan[0].second == p.first.second)
						swan_pos[0] = cnt + 1;
					else if (swan[1].first == p.first.first && swan[1].second == p.first.second)
						swan_pos[1] = cnt + 1;

					for (int k = 0; k < 4; k++)
					{
						int nx = p.first.second + dx[k];
						int ny = p.first.first + dy[k];

						if (nx >= 0 && nx < C && ny >= 0 && ny < R && !visit[ny][nx])
						{
							//cout << "test1 : " << nx << " " << ny << '\n';

							if (arr[ny][nx] == -2)
							{
								arr[ny][nx] = cnt + 1;
								q.push({{ny, nx}, cnt + 1});
							}
							else if (arr[ny][nx] == -1)
								v.push_back({{ny, nx}, cnt + 1});
							visit[ny][nx] = true;
						}
					}
				}
				cnt++;
			}
		}
	}
	for (int k = 0; k < v.size(); k++)
	{
		// cout << v[k].first.first << " " << v[k].first.second << '\n';
		q.push(v[k]);
	}
	//v.clear();

	// cout << "-----------------------\n";
	// for (int i = 0; i < R; i++)
	// {
	// 	for (int j = 0; j < C; j++)
	// 		cout << arr[i][j] << ' ';
	// 	cout << '\n';
	// }
	// cout << "=======================\n";
	// cout << swan_pos[0] << " " << swan_pos[1] << '\n';

	for (int i = 1; i <= 562501; i++)
		parent[i] = i;
	
	int answer = 0;
	while (find(parent[swan_pos[0]]) != find(parent[swan_pos[1]]))
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			auto p = q.front().first;
			int pos = q.front().second;
			q.pop();

			arr[p.first][p.second] = pos;

			// cout << "test : " << p.first << " " << p.second << '\n';

			for (int j = 0; j < 4; j++)
			{
				int nx = p.second + dx[j];
				int ny = p.first + dy[j];

				if (nx >= 0 && nx < C && ny >= 0 && ny < R && arr[ny][nx] != pos)
				{
					if (arr[ny][nx] != -1)
					{
						if (find(parent[arr[p.first][p.second]]) != find(parent[arr[ny][nx]]))
							make_union(parent[arr[p.first][p.second]], parent[arr[ny][nx]]);
					}
					else
					{
						if (!visit[ny][nx])
						{
							q.push({{ny, nx}, pos});
							visit[ny][nx] = true;
						}
					}
				}
			}
		}

		// cout << "-----------------------\n";
		// for (int i = 0; i < R; i++)
		// {
		// 	for (int j = 0; j < C; j++)
		// 		cout << arr[i][j] << ' ';
		// 	cout << '\n';
		// }
		answer++;
	}
	cout << answer << '\n';
	return 0;
}