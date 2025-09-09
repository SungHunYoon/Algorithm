#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
int D[251][251];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	fill(&D[0][0], &D[N + 1][0], 1e9);
	for (int i = 1; i <= M; i++) {
		int u, v, b;
		cin >> u >> v >> b;
		D[u][v] = D[v][u] = 0;
		if (!b) D[v][u] = 1;
	}
	for (int i = 1; i <= N; i++) {
		D[i][i] = 0;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	cin >> K;
	while (K--) {
		int s, e;
		cin >> s >> e;
		cout << D[s][e] << '\n';
	}

	return 0;
}