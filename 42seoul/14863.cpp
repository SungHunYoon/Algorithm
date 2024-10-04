#include <iostream>
#include <tuple>

using namespace std;
using iiii = tuple<int, int, int, int>;

int N, K;
iiii A[101];
int D[101][100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		A[i] = {a, b, c, d};
		fill(D[i], D[i] + K + 1, -1);
	}
	auto [w, x, y, z] = A[1];
	if (w <= K)
		D[1][w] = x;
	if (y <= K) {
		D[1][y] = max(D[1][y], z);
	}
	for (int i = 2; i <= N; i++) {
		auto [a, b, c, d] = A[i];
		for (int j = 0; j <= K; j++) {
			if (D[i - 1][j] >= 0 && j + a <= K)
				D[i][j + a] = max(D[i][j + a], D[i - 1][j] + b);
			if (D[i - 1][j] >= 0 && j + c <= K)
				D[i][j + c] = max(D[i][j + c], D[i - 1][j] + d);
		}
	}
	int answer = 0;
	for (int i = 0; i <= K; i++)
		answer = max(answer, D[N][i]);
	cout << answer << '\n';
	return 0;
}