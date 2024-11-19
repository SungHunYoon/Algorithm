#include <iostream>
#include <algorithm>

using namespace std;

int N, M, R;
int A[301][301];

void printArray() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
}

void rotateArray(int r, int cnt) {
	while (cnt--) {
		int tmp = A[r][r];
		for (int i = 1 + r; i < N - r; i++)
			swap(A[i][r], tmp);
		for (int i = 1 + r; i < M - r; i++)
			swap(A[N - 1 - r][i], tmp);
		for (int i = N - 2 - r; i >= r; i--)
			swap(A[i][M - 1 - r], tmp);
		for (int i = M - 2 - r; i >= r; i--)
			swap(A[r][i], tmp);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	int r = min(N, M) / 2;
	for (int i = 0; i < r; i++)
		rotateArray(i, R % (((N - i * 2) * 2) + (((M - i * 2) - 2) * 2)));
	printArray();
	return 0;
}