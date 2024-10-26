#include <iostream>

using namespace std;

#define MOD 1000000003

int N, K;
int D[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	if (N / 2 < K) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i <= N; i++) {
		D[0][i] = 1;
		D[1][i] = i;
	}
	for (int i = 2; i <= K; i++) {
		for (int j = 2; j <= N; j++) {
			int idx = j - 2;
			if (j == N) idx--;
			D[i][j] = (D[i][j - 1] + D[i - 1][idx]) % MOD;
		}
	}
	cout << D[K][N] << '\n';
	return 0;
}