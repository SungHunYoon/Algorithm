#include <iostream>

using namespace std;

int H, W, T;
int A[501][501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> H >> W;
	// for (int i = 0; i < H; i++)
	// 	for (int j = 0; j < W; j++)
	// 		A[i][j] = 2;
	int answer = H * W;
	for (int i = 0; i < W; i++)
	{
		cin >> T;
		answer -= T;
		for (int j = H - T; j < H; j++)
			A[j][i] = 1;
	}
	for (int i = 0; i < H; i++)
	{
		int prev = -1;
		for (int j = 0; j < W; j++)
		{
			if (prev == -1)
			{
				if (A[i][j] == 0)
				{
					answer--;
					continue;
				}
				prev = j;
			}
			else
			{
				if (A[i][j] == 1)
					prev = j;
			}
		}
		if (prev != -1)
			answer -= (W - 1) - prev;
	}
	cout << answer << '\n';
	return 0;
}