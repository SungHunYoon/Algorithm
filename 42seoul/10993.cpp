#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
char A[(1 << 10)][(1 << 10) * 2];

void DQ(int n, int sr, int er) {
	if (n == 0) return;
	int c = (((1 << n) - 1) * 2 - 1) / 2;
	if (n % 2 == 1) {
		for (int i = 0; i <= c; i++)
			A[er][C + i] = A[er][C - i] = '*';
		for (int i = sr; i < er; i++)
			A[i][C + (i - sr)] = A[i][C - (i - sr)] = '*';
	} else {
		for (int i = 0; i <= c; i++)
			A[sr][C + i] = A[sr][C - i] = '*';
		for (int i = sr + 1, j = c - 1; i < er; i++, j--)
			A[i][C + j] = A[i][C - j] = '*';
	}
	if (n % 2 == 1)
		DQ(n - 1, (sr + er) / 2, er);
	else
		DQ(n - 1, sr + 1, (sr + er) / 2);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	fill(&A[0][0], &A[(1 << N)][0], ' ');
	C = (((1 << N) - 1) * 2 - 1) / 2;
	DQ(N, 0, (1 << N) - 1 - (N % 2 ? 1 : 0));
	for (int i = 0; i < (1 << N) - 1; i++) {
		int last = 0;
		for (int j = 0; j < ((1 << N) - 1) * 2 - 1; j++)
			if (A[i][j] == '*') last = j;
		for (int j = 0; j <= last; j++)
			cout << A[i][j];
		cout << '\n'; 
	}
	return 0;
}