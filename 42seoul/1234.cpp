#include <iostream>
#include <vector>

using namespace std;

int N, R, G, B;

long D[11][101][101][101];

long factorial(int n) {
	long ret = 1;
	for (int i = 1; i <= n; i++) {
		ret *= i;
	}
	return ret;
}

long comb(long n, long r) {
	return factorial(n) / (factorial(r) * factorial(n - r));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> R >> G >> B;
	D[0][R][G][B] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= R; j++) {
			for (int k = 0; k <= G; k++) {
				for (int l = 0; l <= B; l++) {
					if (!D[i - 1][j][k][l]) continue;
					if (j >= i) D[i][j - i][k][l] += D[i - 1][j][k][l];
					if (k >= i) D[i][j][k - i][l] += D[i - 1][j][k][l];
					if (l >= i) D[i][j][k][l - i] += D[i - 1][j][k][l];
					if (i % 2 == 0) {
						if (j >= i / 2 && k >= i / 2) D[i][j - i / 2][k - i / 2][l] += D[i - 1][j][k][l] * comb(i, i / 2);
						if (j >= i / 2 && l >= i / 2) D[i][j - i / 2][k][l - i / 2] += D[i - 1][j][k][l] * comb(i, i / 2);
						if (k >= i / 2 && l >= i / 2) D[i][j][k - i / 2][l - i / 2] += D[i - 1][j][k][l] * comb(i, i / 2);
					}
					if (i % 3 == 0 && j >= i / 3 && k >= i / 3 && l >= i / 3) {
						D[i][j - i / 3][k - i / 3][l - i / 3] += D[i - 1][j][k][l] * comb(i, i / 3) * comb(i - i / 3, i / 3);
					}
				}
			}
		}
	}
	long answer = 0;
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= G; j++) {
			for (int k = 0; k <= B; k++) {
				answer += D[N][i][j][k];
			}
		}
	}
	cout << answer << '\n';
	return 0;
}