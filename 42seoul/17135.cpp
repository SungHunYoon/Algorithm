#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, D;
int A[15][15];
bool visit[15];
int answer;

void dfs(int idx, int cnt)
{
	if (cnt >= 3)
	{
		int t[15][15];
		memcpy(t, A, sizeof(A));
		vector<int> v;
		for (int i = 0; i < M; i++)
		{
			if (visit[i])
				v.push_back(i);
		}
		int temp = 0;
		for (int l = 0; l < N; l++)
		{
			vector<pair<int, int>> kill;
			for (int i = 0; i < v.size(); i++)
			{
				pair<int, int> p;
				int minD = 1e9;
				for (int k = 0; k < M; k++)
				{
					for (int j = N - 1 - l; j >= 0; j--)
					{
						int d = abs((N - l) - j) + abs(v[i] - k);
						if (t[j][k] == 1 && d <= D && minD > d)
						{
							minD = d;
							p = {j, k};
						}
					}
				}
				if (minD != 1e9)
					kill.push_back(p);
			}
			for (int i = 0; i < kill.size(); i++)
			{
				if (t[kill[i].first][kill[i].second] == 1)
				{
					t[kill[i].first][kill[i].second] = 0;
					temp++;
				}
			}
		}
		answer = max(answer, temp);
		return;
	}

	for (int i = idx; i < M; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(i + 1, cnt + 1);
			visit[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	dfs(0, 0);
	cout << answer << '\n';
	return 0;
}
