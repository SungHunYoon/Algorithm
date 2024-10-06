#include <iostream>
#include <algorithm>

using namespace std;

int N, M, T;
int A[101];
int D[101][3][41];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> T;
		A[T] = 1;
	}

	for (int i = 0; i <= N; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k <= 40; k++)
				D[i][j][k] = 1e9;

	D[0][0][0] = 0; D[1][0][0] = 10000;
	D[0][1][0] = 0; D[3][1][1] = 25000;
	D[0][2][0] = 0; D[5][2][2] = 37000;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 40; j++) {
			if (A[i] == 1) {
				D[i][0][j] = min(D[i][0][j], D[i - 1][0][j]);
				D[i][1][j] = min(D[i][1][j], D[i - 1][1][j]);
				D[i][2][j] = min(D[i][2][j], D[i - 1][2][j]);
			} else {
				D[i][0][j] = min(min(D[i - 1][0][j], D[i - 1][1][j]), D[i - 1][2][j]) + 10000;
				if (j + 3 <= 40)
					D[i][0][j] = min(D[i][0][j], min(D[i - 1][0][j + 3], min(D[i - 1][1][j + 3], D[i - 1][2][j + 3])));

				if (i >= 3 && j >= 1) {
					for (int k = 1; k <= 3; k++)
						D[i][1][j] = min(D[i][1][j], min(min(D[i - k][0][j - 1], D[i - k][1][j - 1]), D[i - k][2][j - 1]) + 25000);
				}
				if (i >= 5 && j >= 2) {
					for (int k = 1; k <= 5; k++)
						D[i][2][j] = min(D[i][2][j], min(min(D[i - k][0][j - 2], D[i - k][1][j - 2]), D[i - k][2][j - 2]) + 37000);
				}
			}
		}
	}
	int answer = 1e9;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j <= 40; j++)
			answer = min(answer, D[N][i][j]);
	cout << answer << '\n';
	return 0;
}