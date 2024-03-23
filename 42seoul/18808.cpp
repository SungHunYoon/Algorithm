#include <iostream>
#include <vector>

using namespace std;

using sticker = vector<vector<int> >;

int N, M, K;
vector<sticker> stk[101];
int arr[41][41];

bool isPutable(int x, int y, int stk_index, int r_index)
{
	if (stk[stk_index][r_index].size() + y > N || stk[stk_index][r_index][0].size() + x > M)
		return false;
	for (int i = y; i < y + stk[stk_index][r_index].size(); i++)
	{
		for (int j = x; j < x + stk[stk_index][r_index][0].size(); j++)
		{
			if (arr[i][j] == 1 && stk[stk_index][r_index][i - y][j - x] == 1)
				return false;
		}
	}
	for (int i = y; i < y + stk[stk_index][r_index].size(); i++)
	{
		for (int j = x; j < x + stk[stk_index][r_index][0].size(); j++)
		{
			if (stk[stk_index][r_index][i - y][j - x] == 1)
				arr[i][j] = stk[stk_index][r_index][i - y][j - x];
		}
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> y >> x;
		sticker tmp(y, vector<int>(x, 0));
		for (int j = 0; j < y; j++)
			for (int k = 0; k < x; k++)
				cin >> tmp[j][k];
		stk[i].push_back(tmp);
		sticker tmp90(x, vector<int>(y, 0));
		for (int j = 0; j < x; j++)
			for (int k = 0; k < y; k++)
				tmp90[j][k] = tmp[y - k - 1][j];
		stk[i].push_back(tmp90);
		sticker tmp180(y, vector<int>(x, 0));
		for (int j = 0; j < y; j++)
			for (int k = 0; k < x; k++)
				tmp180[j][k] = tmp[y - j - 1][x - k - 1];
		stk[i].push_back(tmp180);
		sticker tmp270(x, vector<int>(y, 0));
		for (int j = 0; j < x; j++)
			for (int k = 0; k < y; k++)
				tmp270[j][k] = tmp[k][x - j - 1];
		stk[i].push_back(tmp270);
	}
	for (int i = 0; i < K; i++)
	{
		bool flag = false;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < N; k++)
			{
				for (int l = 0; l < M; l++)
				{
					if (isPutable(l, k, i, j))
					{
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
				answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}