#include <iostream>

using namespace std;

int N, M, R, C, D;
int A[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool searchNotEmpty()
{
	for (int i = 0; i < 4; i++)
	{
		int nx = C + dx[i];
		int ny = R + dy[i];
		
		if (A[ny][nx] == 0)
			return true;
	}
	return false;
}

void rotateRobot()
{
	while (1)
	{
		D--;
		if (D < 0)
			D = 3;
		if (D == 0)
		{
			if (A[R - 1][C] == 0)
			{
				R -= 1;
				return;
			}
		}
		else if (D == 1)
		{
			if (A[R][C + 1] == 0)
			{
				C += 1;
				return;
			}
		}
		else if (D == 2)
		{
			if (A[R + 1][C] == 0)
			{
				R += 1;
				return;
			}
		}
		else
		{
			if (A[R][C - 1] == 0)
			{
				C -= 1;
				return;
			}
		}
	}
}

bool moveBack()
{
	if (D == 0)
		R += 1;
	else if (D == 1)
		C -= 1;
	else if (D == 2)
		R -= 1;
	else
		C += 1;
	if (A[R][C] == 1)
		return false;
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R >> C >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	int answer = 0;
	while (1)
	{
		if (A[R][C] == 0)
		{
			A[R][C] = 2;
			answer++;
		}
		if (searchNotEmpty())
			rotateRobot();
		else if (!moveBack())
			break;
	}
	cout << answer << '\n';
	return 0;
}