#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
long A[50], P[14], Q[14];
long D[50][901];
long B[50];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= K; i++) {
		cin >> P[i] >> Q[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (A[i] * 900 < P[j]) continue;
			long time = P[j] / A[i] + (P[j] % A[i] != 0);
			for (int k = 900; k >= time; k--) {
				D[i][k] = max(D[i][k], D[i][k - time] + Q[j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		B[i] = D[i][900];
	}
	sort(B + 1, B + N + 1);
	long answer = 0;
	for (int i = 0; i < M; i++) {
		answer += B[N - i];
	}
	cout << answer << '\n';
	return 0;
}