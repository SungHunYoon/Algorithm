#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K;
int A[101][101];
int row = 3, col = 3;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

void simulation()
{
	if (row >= col)
	{
		int maxCol = 0;
		for (int i = 1; i <= row; i++)
		{
			map<int, int> m;
			vector<pair<int, int>> v;

			for (int j = 1; j <= col; j++)
			{
				if (A[i][j] > 0)
					m[A[i][j]]++;
			}
			for (auto [num, cnt] : m)
				v.push_back({num, cnt});
			sort(v.begin(), v.end(), cmp);
			maxCol = max(maxCol, (int)v.size() * 2);
			if (maxCol >= 100)
				maxCol = 100;
			for (int j = 0; j < 50; j++)
			{
				if (j < v.size())
				{
					A[i][j * 2 + 1] = v[j].first;
					A[i][j * 2 + 2] = v[j].second;
				}
				else
				{
					A[i][j * 2 + 1] = 0;
					A[i][j * 2 + 2] = 0;
				}
			}
		}
		col = maxCol;
	}
	else
	{
		int maxRow = 0;
		for (int i = 1; i <= col; i++)
		{
			map<int, int> m;
			vector<pair<int, int>> v;
			
			for (int j = 1; j <= row; j++)
			{
				if (A[j][i] > 0)
					m[A[j][i]]++;
			}
			for (auto [num, cnt] : m)
				v.push_back({num, cnt});
			sort(v.begin(), v.end(), cmp);
			maxRow = max(maxRow, (int)v.size() * 2);
			if (maxRow >= 100)
				maxRow = 100;
			for (int j = 0; j < 50; j++)
			{
				if (j < v.size())
				{
					A[j * 2 + 1][i] = v[j].first;
					A[j * 2 + 2][i] = v[j].second;
				}
				else
				{
					A[j * 2 + 1][i] = 0;
					A[j * 2 + 2][i] = 0;
				}
			}
		}
		row = maxRow;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C >> K;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> A[i][j];
	for (int i = 0; i <= 100; i++)
	{
		if (A[R][C] == K)
		{
			cout << i << '\n';
			return 0;
		}
		simulation();
	}
	cout << "-1\n";
	return 0;
}