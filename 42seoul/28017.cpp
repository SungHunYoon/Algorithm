#include <iostream>

using namespace std;

int N, M;
int A[501][501];
int D[501][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int minV = 1e9;
			for (int k = 1; k <= M; k++) {
				if (j == k) continue;
				minV = min(minV, D[i - 1][k]);
			}
			D[i][j] = minV + A[i][j];
		}
	}
	int answer = 1e9;
	for (int i = 1; i <= M; i++)
		answer = min(answer, D[N][i]);
	cout << answer << '\n';
	return 0;
}