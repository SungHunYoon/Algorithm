#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[101];
int O[4];
int C[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < 4; i++)
		cin >> O[i];
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < O[i]; j++)
			C[idx++] = i;
	}
	int maxAnswer = -1e9;
	int minAnswer = 1e9;
	do
	{
		int number = A[0];
		for (int i = 0; i < idx; i++)
		{
			if (C[i] == 0)
				number += A[i + 1];
			else if (C[i] == 1)
				number -= A[i + 1];
			else if (C[i] == 2)
				number *= A[i + 1];
			else
				number /= A[i + 1];
		}
		minAnswer = min(minAnswer, number);
		maxAnswer = max(maxAnswer, number);
	} while (next_permutation(C, C + idx));
	cout << maxAnswer << '\n' << minAnswer << '\n';
	return 0;
}