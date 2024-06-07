#include <iostream>

using namespace std;

int N, L;
int A[101][101];

int checkPath(int x, int y, int d, int c)
{
	if (d == 0)
	{
		int diff = A[y][x] - A[y + 1][x];
		if (diff == 1)
		{
			if (y + L >= N)
				return 0;
			for (int i = y + 1; i <= y + L; i++)
			{
				if (A[y][x] - 1 != A[i][x])
					return 0;
			}
			return L;
		}
		else if (diff == -1)
		{
			if (c < L)
				return 0;
			return -1;
		}
		else
			return 0;
	}
	else
	{
		int diff = A[y][x] - A[y][x + 1];
		if (diff == 1)
		{
			if (x + L >= N)
				return 0;
			for (int i = x + 1; i <= x + L; i++)
			{
				if (A[y][x] - 1 != A[y][i])
					return 0;
			}
			return L;
		}
		else if (diff == -1)
		{
			if (c < L)
				return 0;
			return -1;
		}
		else
			return 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int c = 1;
		bool flag = true;
		for (int j = 0; j < N - 1; j++)
		{
			if (A[j][i] == A[j + 1][i])
			{
				c++;
				continue;
			}
			int inc;
			if ((inc = checkPath(i, j, 0, c)) == 0)
			{
				flag = false;
				break;
			}
			if (inc == -1)
				c = 1;
			else
			{
				c = 0;
				j += inc - 1;
			}
		}
		if (flag)
			answer++;
		c = 1;
		flag = true;
		for (int j = 0; j < N - 1; j++)
		{
			if (A[i][j] == A[i][j + 1])
			{
				c++;
				continue;
			}
			int inc;
			if ((inc = checkPath(j, i, 1, c)) == 0)
			{
				flag = false;
				break;
			}
			if (inc == -1)
				c = 1;
			else
			{
				c = 0;
				j += inc - 1;
			}
		}
		if (flag)
			answer++;
	}
	cout << answer << '\n';
	return 0;
}