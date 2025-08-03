#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[1001][1001];
int D[1002][1002];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	fill(&D[0][0], &D[1002][0], -1e9);
	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= M; j++) {
			D[i][j] = max(D[i + 1][j], D[i][j - 1]);
			if (D[i][j] == -1e9) {
				D[i][j] = A[i][j];
			} else {
				D[i][j] += A[i][j];
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			D[i][j] = max({D[i][j], D[i - 1][j], D[i][j - 1]}) + A[i][j];
		}
	}
	cout << D[N][M] << '\n';
	return 0;
}