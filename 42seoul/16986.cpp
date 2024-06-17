#include <iostream>

using namespace std;

int N, K;
int A[10][10];
int GM[3][21];
int winCnt[3];
int idx[3];
bool visit[10];

int nextIdx()
{
	static int idx;

	idx = (idx + 1) % 3;
	return idx;
}

int judge(int val, int aIdx, int bIdx)
{
	if (val == 2)
		return aIdx;
	else if (val == 1)
	{
		if (aIdx > bIdx)
			return aIdx;
		else
			return bIdx;
	}
	else
		return bIdx;
}

int simulation(int cnt, int a, int b, int aIdx, int bIdx)
{
	int win = judge(A[a][b], aIdx, bIdx);
	winCnt[win]++;
	if (winCnt[win] >= K)
	{
		winCnt[win]--;
		if (win == 0)
			return 1;
		else
			return 0;
	}
	int next = nextIdx();
	while (aIdx == next || bIdx == next) next = nextIdx();
	if (next == 0)
	{
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				if (simulation(cnt + 1, GM[win][idx[win]++], i, win, next) == 1)
					return 1;
				--idx[win];
				visit[i] = false;
			}
		}
	}
	else if (win == 0)
	{
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				if (simulation(cnt + 1, i, GM[next][idx[next]++], win, next) == 1)
					return 1;
				--idx[next];
				visit[i] = false;
			}
		}
	}
	else
	{
		if (simulation(cnt + 1, GM[win][idx[win]++], GM[next][idx[next]++], win, next) == 1)
			return 1;
		--idx[win];
		--idx[next];
	}
	winCnt[win]--;
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	for (int i = 0; i < 20; i++)
		cin >> GM[1][i];
	for (int i = 0; i < 20; i++)
		cin >> GM[2][i];
	for (int i = 1; i <= N; i++)
	{
		visit[i] = true;
		if (simulation(0, i, GM[1][idx[1]++], 0, 1) == 1)
		{
			cout << "1\n";
			return 0;
		}
		--idx[1];
		visit[i] = false;
	}
	cout << "0\n";
	return 0;
}