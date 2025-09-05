#include <iostream>

using namespace std;

int N, M, K;
int D[16][16];
int E[16][16];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	D[0][1] = 1;
	int r = N + 1, c = M + 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int num = ((i - 1) * M) + j;
			D[i][j] = D[i - 1][j] + D[i][j - 1];
			if (num == K) {
				r = i;
				c = j;
				E[i - 1][j] = D[i][j];
			}
		}
	}
	for (int i = r; i <= N; i++) {
		for (int j = c; j <= M; j++) {
			E[i][j] = E[i - 1][j] + E[i][j - 1];
		}
	}
	cout << (K == 0 ? D[N][M] : E[N][M]) << '\n';
	return 0;
}