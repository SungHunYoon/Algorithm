#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[1001][1001];
int D[3][1002][1002];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	fill(&D[0][0][0], &D[3][0][0], 1e9);
	for (int i = 1; i <= M; i++)
		D[0][1][i] = D[1][1][i] = D[2][1][i] = A[1][i];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			D[0][i][j] = min(D[1][i - 1][j - 1], D[2][i - 1][j + 1]) + A[i][j];
			D[1][i][j] = min(D[0][i - 1][j], D[2][i - 1][j + 1]) + A[i][j];
			D[2][i][j] = min(D[0][i - 1][j], D[1][i - 1][j - 1]) + A[i][j];
		}
	}
	int answer = 1e9;
	for (int i = 1; i <= M; i++) {
		answer = min(answer, D[0][N][i]);
		answer = min(answer, D[1][N][i]);
		answer = min(answer, D[2][N][i]);
	}
	cout << answer << '\n';
	return 0;
}