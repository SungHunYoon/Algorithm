#include <iostream>
#include <algorithm>

using namespace std;

bool T[4][8];
int K, N, D;

void rotateClock(int idx)
{
	rotate(T[idx], T[idx] + 8 - 1, T[idx] + 8);
}

void rotateReverseClock(int idx)
{
	rotate(T[idx], T[idx] + 1, T[idx] + 8);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	for (int i = 0; i < 4; i++)
	{
		cin >> str;
		for (int j = 0; j < 8; j++)
		{
			if (str[j] == '1')
				T[i][j] = true;
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> N >> D;
		N -= 1;
		int leftCnt = 0;
		int rightCnt = 0;

		for (int j = N + 1; j < 4; j++, rightCnt++)
		{
			if (T[j - 1][2] == T[j][6])
				break;
		}

		for (int j = N - 1; j >= 0; j--, leftCnt++)
		{
			if (T[j + 1][6] == T[j][2])
				break;
		}

		if (D == 1)
			rotateClock(N);
		else
			rotateReverseClock(N);

		int direction = D == 1 ? -1 : 1;
		for (int j = 1; j <= rightCnt; j++)
		{
			if (direction == 1)
			{
				rotateClock(N + j);
				direction = -1;
			}
			else
			{
				rotateReverseClock(N + j);
				direction = 1;
			}
		}

		direction = D == 1 ? -1 : 1;
		for (int j = 1; j <= leftCnt; j++)
		{
			if (direction == 1)
			{
				rotateClock(N - j);
				direction = -1;
			}
			else
			{
				rotateReverseClock(N - j);
				direction = 1;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 4; i++)
		answer += (T[i][0] << i);
	cout << answer << '\n';
	return 0;
}