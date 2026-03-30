#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<vector<char>> A(N + 1, vector<char>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	vector<vector<vector<long>>> D(3, vector<vector<long>>(N + 1, vector<long>(M + 1)));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			D[0][i][j] = (D[0][i - 1][j] - D[0][i - 1][j - 1] + D[0][i][j - 1]) % MOD;
			D[1][i][j] = (D[1][i - 1][j] - D[1][i - 1][j - 1] + D[1][i][j - 1]) % MOD;
			D[2][i][j] = (D[2][i - 1][j] - D[2][i - 1][j - 1] + D[2][i][j - 1]) % MOD;
			if (D[0][i][j] < 0) D[0][i][j] += MOD;
			if (D[1][i][j] < 0) D[1][i][j] += MOD;
			if (D[2][i][j] < 0) D[2][i][j] += MOD;

			if (A[i][j] == 'E') {
				D[0][i][j]++;
			} else if (A[i][j] == 'S') {
				D[1][i][j] = (D[1][i][j] + D[0][i][j]) % MOD;
			} else {
				D[2][i][j] = (D[2][i][j] + D[1][i][j]) % MOD;
			}
		}
	}
	cout << D[2][N][M] << '\n';

	return 0;
}