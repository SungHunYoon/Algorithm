#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int X[501], Y[501], D[501][501];

int getDistance(int a, int b) {
	return (abs(X[a] - X[b]) + abs(Y[a] - Y[b]));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i];
	}
	fill(&D[0][0], &D[501][0], 1e9);
	D[0][1] = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K + 1; j++) {
			if (i - j < 1) break;
			for (int k = 0; k <= K; k++) {
				D[k + j - 1][i] = min(D[k + j - 1][i], D[k][i - j] + getDistance(i, i - j));
			}
		}
	}
	int answer = 1e9;
	for (int i = 0; i <= K; i++) {
		answer = min(answer, D[i][N]);
	}
	cout << answer << '\n';
	return 0;
}