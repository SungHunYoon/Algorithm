#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int C[1001];
int A[1001];

void sequenceIncDesc(int idx, bool flag)
{
	for (int i = idx; i < N; i++)
	{
		if (flag)
		{
			if (A[i] <= 0)
				return;
			A[i]--;
		}
		else
		{
			if (A[i] >= 0)
				return;
			A[i]++;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> C[i];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		A[i] -= C[i];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		while (A[i] != 0)
		{
			if (A[i] > 0)
				sequenceIncDesc(i, true);
			else
				sequenceIncDesc(i, false);
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}
