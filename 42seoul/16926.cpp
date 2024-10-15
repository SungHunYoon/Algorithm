#include <iostream>

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

void rotateArray() {
	int C = min(N, M) / 2;

	for (int j = 0; j < C; j++) {
		int tmp = A[j][j];
		for (int i = j + 1; i < N - j; i++)
			swap(A[i][j], tmp);
		for (int i = j + 1; i < M - j; i++)
			swap(A[N - j - 1][i], tmp);
		for (int i = N - j - 2; i >= j; i--)
			swap(A[i][M - j - 1], tmp);
		for (int i = M - j - 2; i >= j; i--)
			swap(A[j][i], tmp);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	for (int i = 0; i < R; i++)
		rotateArray();
	printArray();
	return 0;
}
