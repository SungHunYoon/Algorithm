#include <iostream>
#include <algorithm>

using namespace std;

int N, M, X, Y, K, T;
int A[21][21];
int D[6];

void moveE()
{
	swap(D[2], D[3]);
	swap(D[2], D[5]);
	swap(D[3], D[0]);
}

void moveW()
{
	swap(D[0], D[3]);
	swap(D[3], D[2]);
	swap(D[3], D[5]);
}

void moveS()
{
	swap(D[0], D[1]);
	swap(D[4], D[5]);
	swap(D[0], D[5]);
}

void moveN()
{
	swap(D[0], D[1]);
	swap(D[1], D[4]);
	swap(D[1], D[5]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> X >> Y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	for (int i = 0; i < K; i++)
	{
		cin >> T;
		if (T == 1)
		{
			if (Y + 1 < M)
			{
				moveE();
				Y += 1;
				if (A[X][Y] != 0)
				{
					D[0] = A[X][Y];
					A[X][Y] = 0;
				}
				else
					A[X][Y] = D[0];
				cout << D[5] << '\n';
			}
		}
		else if (T == 2)
		{
			if (Y - 1 >= 0)
			{
				moveW();
				Y -= 1;
				if (A[X][Y] != 0)
				{
					D[0] = A[X][Y];
					A[X][Y] = 0;
				}
				else
					A[X][Y] = D[0];
				cout << D[5] << '\n';
			}
		}
		else if (T == 3)
		{
			if (X - 1 >= 0)
			{
				moveN();
				X -= 1;
				if (A[X][Y] != 0)
				{
					D[0] = A[X][Y];
					A[X][Y] = 0;
				}
				else
					A[X][Y] = D[0];
				cout << D[5] << '\n';
			}
		}
		else
		{
			if (X + 1 < N)
			{
				moveS();
				X += 1;
				if (A[X][Y] != 0)
				{
					D[0] = A[X][Y];
					A[X][Y] = 0;
				}
				else
					A[X][Y] = D[0];
				cout << D[5] << '\n';
			}
		}
	}
	return 0;
}