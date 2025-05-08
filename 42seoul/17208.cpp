#include <iostream>

using namespace std;

int N, M, K;
int X[101], Y[101];
int D[301][301];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> X[i] >> Y[i];
	for (int i = 1; i <= N; i++) {
		for (int j = M; j >= X[i]; j--) {
			for (int k = K; k >= Y[i]; k--) {
				D[j][k] = max(D[j][k], D[j - X[i]][k - Y[i]] + 1);
			}
		}
	}
	cout << D[M][K] << '\n';
	return 0;
}