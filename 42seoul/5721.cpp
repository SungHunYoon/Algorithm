#include <iostream>
#include <vector>

using namespace std;

int M, N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> M >> N) {
		if (M == 0 && N == 0)
			break;
		vector<vector<int>> A(M + 1, vector<int>(N + 1));
		vector<vector<int>> D(M + 1, vector<int>(N + 1));
		for (int i = 1; i <= M; i++)
			for (int j = 1; j <= N; j++)
				cin >> A[i][j];
		for (int i = 1; i <= M; i++) {
			D[i][1] = A[i][1];
			for (int j = 2; j <= N; j++)
				D[i][j] = max(D[i][j - 1], D[i][j - 2] + A[i][j]);
		}
		for (int i = 2; i <= M; i++)
			D[i][N] = max(D[i - 1][N], D[i - 2][N] + D[i][N]);
		cout << D[M][N] << '\n';
	}

	return 0;
}