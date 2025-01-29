#include <iostream>
#include <algorithm>

using namespace std;

int N, T, M;
int S[1001], X[1001], Y[1001];
int A[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> T;
	fill(&A[0][0], &A[1001][0], 1e9);
	for (int i = 1; i <= N; i++)
		A[i][i] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> S[i] >> X[i] >> Y[i];
		for (int j = 1; j < i; j++) {
			int d = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
			A[i][j] = A[j][i] = d;
			if (!S[i] || !S[j]) continue;
			A[i][j] = A[j][i] = min(A[i][j], T);
		}
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout << A[x][y] << '\n';
	}
	return 0;
}