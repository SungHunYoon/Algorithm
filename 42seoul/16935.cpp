#include <iostream>
#include <algorithm>

using namespace std;

int N, M, R, K;
int A[101][101];
int T[101][101];

void printArray() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
}

void copyArray() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = T[i][j];
}

void reverseUpDown() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			T[i][j] = A[N - i - 1][j];
	copyArray();
}

void reverseLeftRight() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			T[i][j] = A[i][M - j - 1];
	copyArray();
}

void rotateLeft() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			T[M - i - 1][j] = A[j][i];
	swap(N, M);
	copyArray();
}

void rotateRight() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			T[i][N - j - 1] = A[j][i];
	swap(N, M);
	copyArray();
}

void clockSubArray() {
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < M / 2; j++)
			T[i][M / 2 + j] = A[i][j];
	for (int i = 0; i < N / 2; i++)
		for (int j = M / 2; j < M; j++)
			T[N / 2 + i][j] = A[i][j];
	for (int i = N / 2; i < N; i++)
		for (int j = M / 2; j < M; j++)
			T[i][j - M / 2] = A[i][j];
	for (int i = N / 2; i < N; i++)
		for (int j = 0; j < M / 2; j++)
			T[i - N / 2][j] = A[i][j];
	copyArray();
}

void counterClockSubArray() {
	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < M / 2; j++)
			T[N / 2 + i][j] = A[i][j];
	for (int i = N / 2; i < N; i++)
		for (int j = 0; j < M / 2; j++)
			T[i][M / 2 + j] = A[i][j];
	for (int i = N / 2; i < N; i++)
		for (int j = M / 2; j < M; j++)
			T[i - N / 2][j] = A[i][j];
	for (int i = 0; i < N / 2; i++)
		for (int j = M / 2; j < M; j++)
			T[i][j - M / 2] = A[i][j];
	copyArray();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	for (int i = 0; i < R; i++) {
		cin >> K;
		if (K == 1)
			reverseUpDown();
		else if (K == 2)
			reverseLeftRight();
		else if (K == 3)
			rotateRight();
		else if (K == 4)
			rotateLeft();
		else if (K == 5)
			clockSubArray();
		else if (K == 6)
			counterClockSubArray();
	}
	printArray();
	return 0;
}