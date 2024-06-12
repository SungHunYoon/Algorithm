#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, M, K, X, Y, Z;
int A[11][11];
int E[11][11];
deque<int> T[11][11];
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void simulate()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int dieT = 0;
			int len = T[i][j].size();
			for (int k = 0; k < len; k++)
			{
				if (E[i][j] >= T[i][j][k])
				{
					E[i][j] -= T[i][j][k];
					T[i][j].push_back(T[i][j][k] + 1);
				}
				else
					dieT += T[i][j][k] / 2;
			}
			for (int k = 0; k < len; k++)
				T[i][j].pop_front();
			E[i][j] += dieT;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int len = T[i][j].size();
			for (int k = 0; k < len; k++)
			{
				if (T[i][j][k] % 5 == 0)
				{
					for (int l = 0; l < 8; l++)
					{
						int nx = j + dx[l];
						int ny = i + dy[l];
						if (1 <= nx && nx <= N && 1 <= ny && ny <= N)
							T[ny][nx].push_front(1);
					}
				}
			}
			E[i][j] += A[i][j];
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			E[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y >> Z;
		T[X][Y].push_back(Z);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			sort(T[i][j].begin(), T[i][j].end());
	for (int i = 0; i < K; i++)
		simulate();
	int answer = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			answer += T[i][j].size();
	cout << answer << '\n';
	return 0;
}