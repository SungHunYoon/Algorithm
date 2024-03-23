#include <iostream>
#include <string>

using namespace std;

int N, M;
int A[51][51];
int B[51][51];

bool convertRowCol(int x, int y)
{
	int destX = x + 3;
	int destY = y + 3;

	if (destX > M || destY > N)
		return false;
	for (int i = y; i < destY; i++)
		for (int j = x; j < destX; j++)
			A[i][j] = !A[i][j];
	return true;
}

bool isEqual()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] != B[i][j])
				return false;
		}
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++)
			A[i][j] = tmp[j] - '0';
	}
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++)
			B[i][j] = tmp[j] - '0';
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] != B[i][j])
			{
				if (convertRowCol(j, i))
					answer++;
			}
		}
	}
	if (isEqual())
		cout << answer << '\n';
	else
		cout << "-1\n";
	return 0;
}