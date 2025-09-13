#include <iostream>
#include <algorithm>

using namespace std;

int N, M, T;
int A[301][301];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> T;
	fill(&A[0][0], &A[301][0], 1e9);
	for (int i = 1; i <= M; i++) {
		int u, v, h;
		cin >> u >> v >> h;
		A[u][v] = h;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (A[i][k] == 1e9 || A[k][j] == 1e9) continue;
				A[i][j] = min(A[i][j], max(A[i][k], A[k][j]));
			}
		}
	}
	while (T--) {
		int s, e;
		cin >> s >> e;
		cout << (A[s][e] == 1e9 ? -1 : A[s][e]) << '\n';
	}

	return 0;
}